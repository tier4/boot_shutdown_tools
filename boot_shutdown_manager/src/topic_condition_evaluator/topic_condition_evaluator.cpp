// Copyright 2025 TIER IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "topic_condition_evaluator/topic_condition_evaluator.hpp"

#include "topic_condition_evaluator/topic_config_parser.hpp"

#include <dynmsg/message_reading.hpp>

namespace topic_condition_evaluator
{

TopicConditionEvaluator::TopicConditionEvaluator()
{
}

void TopicConditionEvaluator::setup(
  rclcpp::Node * node, const std::string & topic_config_param_key,
  const std::string & qos_profile_path_param_key, ConditionNotificationCallback callback)
{
  if (node == nullptr) {
    throw std::invalid_argument("TopicConditionEvaluator: node is nullptr");
  }

  node_ = node;
  callback_ = callback;

  node_->get_parameter_or(qos_profile_path_param_key, qos_profile_path_, std::string(""));

  // Parse topic conditions from parameters
  topic_config_ = parse_config(*node_, topic_config_param_key);

  // Initialize a subscription entry for each topic
  for (const auto & [topic_name, _] : topic_config_.topic_conditions) {
    subscriptions_[topic_name] = Subscription();
  }

  // Used for configuring QoS settings when creating GenericSubscription
  try {
    qos_profile_ = YAML::LoadFile(qos_profile_path_);
  } catch (const YAML::Exception & e) {
    RCLCPP_WARN(node_->get_logger(), "Failed to load QoS profile: %s", e.what());
  }

  using namespace std::literals::chrono_literals;
  timer_ = rclcpp::create_timer(
    node_, node_->get_clock(), 1s, std::bind(&TopicConditionEvaluator::on_timer, this));

  if (!create_generic_subscriptions()) {
    using namespace std::literals::chrono_literals;
    subscription_timer_ = rclcpp::create_timer(
      node_, node_->get_clock(), 1s,
      std::bind(&TopicConditionEvaluator::on_subscription_timer, this));
  }
}

void TopicConditionEvaluator::on_timer()
{
  const auto any_publisher_exists = update_received_flags();
  if (!any_publisher_exists) {
    notification_.is_condition_met.reset();
    notification_.reason = "No message received";
  }

  notify();
}

void TopicConditionEvaluator::on_subscription_timer()
{
  if (create_generic_subscriptions()) {
    subscription_timer_->cancel();
  }
}

bool TopicConditionEvaluator::create_generic_subscriptions()
{
  bool is_completed = true;
  for (auto & [topic_name, subscription] : subscriptions_) {
    if (subscription.generic_subscription != nullptr) {
      continue;
    }

    // Get topic type
    const auto topic_info = node_->get_publishers_info_by_topic(topic_name);
    if (topic_info.empty()) {
      is_completed = false;
      continue;
    }

    // If multiple publishers exist for a single topic name,
    // only the first publisher's message will be subscribed to.
    const auto topic_type = topic_info[0].topic_type();

    // Create SerializationBase
    const std::string typesupport_identifier = "rosidl_typesupport_introspection_cpp";
    auto type_support_lib = rclcpp::get_typesupport_library(topic_type, typesupport_identifier);
    auto type_support_handle =
      rclcpp::get_typesupport_handle(topic_type, typesupport_identifier, *type_support_lib);
    subscription.serialization_base =
      std::make_shared<rclcpp::SerializationBase>(type_support_handle);

    // Create GenericSubscription
    using std::placeholders::_1;
    std::string package = topic_type.substr(0, topic_type.find('/'));
    std::string name = topic_type.substr(topic_type.rfind('/') + 1);
    InterfaceTypeName interface_type_name{package, name};
    const TypeInfo_Cpp * dynmsg_typeinfo = dynmsg::cpp::get_type_info(interface_type_name);
    if (dynmsg_typeinfo == nullptr) {
      RCLCPP_WARN(node_->get_logger(), "typeinfo is null: %s", topic_name.c_str());
      continue;
    }

    rclcpp::QoS qos = rclcpp::QoS(1);
    if (qos_profile_[topic_name]) {
      qos = create_qos_from_yaml(qos_profile_[topic_name]);
      RCLCPP_INFO(
        node_->get_logger(), "QoS: %s\n%s\n", topic_name.c_str(),
        YAML::Dump(qos_profile_[topic_name]).c_str());
    } else {
      RCLCPP_WARN(node_->get_logger(), "QoS profile not found: %s", topic_name.c_str());
    }

    subscription.generic_subscription = node_->create_generic_subscription(
      topic_name, topic_type, qos,
      [this, &subscription, topic_name,
       dynmsg_typeinfo](std::shared_ptr<rclcpp::SerializedMessage> msg) {
        this->generic_subscription_callback(
          msg, topic_name, topic_config_.topic_conditions[topic_name], subscription,
          dynmsg_typeinfo);
      });
  }

  return is_completed;
}

rclcpp::QoS TopicConditionEvaluator::create_qos_from_yaml(const YAML::Node & qos_node) const
{
  // Read optional parameters from the YAML node, or fall back to defaults
  int depth = qos_node["depth"] ? qos_node["depth"].as<int>() : 10;
  std::string history_str =
    qos_node["history"] ? qos_node["history"].as<std::string>() : "keep_last";
  std::string reliability_str =
    qos_node["reliability"] ? qos_node["reliability"].as<std::string>() : "reliable";
  std::string durability_str =
    qos_node["durability"] ? qos_node["durability"].as<std::string>() : "volatile";

  // Convert string values to corresponding enum types
  rmw_qos_history_policy_t history =
    history_str == "keep_all" ? RMW_QOS_POLICY_HISTORY_KEEP_ALL : RMW_QOS_POLICY_HISTORY_KEEP_LAST;

  rmw_qos_reliability_policy_t reliability = reliability_str == "best_effort"
                                               ? RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT
                                               : RMW_QOS_POLICY_RELIABILITY_RELIABLE;

  rmw_qos_durability_policy_t durability = durability_str == "transient_local"
                                             ? RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL
                                             : RMW_QOS_POLICY_DURABILITY_VOLATILE;

  // Create QoS profile
  rclcpp::QoS qos(rclcpp::QoSInitialization(history, depth));
  qos.reliability(reliability).durability(durability);

  return qos;
}

void TopicConditionEvaluator::generic_subscription_callback(
  std::shared_ptr<rclcpp::SerializedMessage> msg, const std::string & topic_name,
  const TopicCondition & topic_condition, Subscription & subscription,
  const TypeInfo_Cpp * dynmsg_typeinfo)
{
  // Create instances of message type
  RosMessage_Cpp message;
  rcutils_allocator_t default_allocator = rcutils_get_default_allocator();
  const auto ret =
    dynmsg::cpp::ros_message_with_typeinfo_init(dynmsg_typeinfo, &message, &default_allocator);
  if (ret != DYNMSG_RET_OK) {
    RCLCPP_WARN_THROTTLE(
      node_->get_logger(), *node_->get_clock(), 5000, "Failed to allocate message: %s",
      topic_name.c_str());
    return;
  }

  // Deserialize message
  const auto serialization_base = subscription.serialization_base;
  serialization_base->deserialize_message(msg.get(), message.data);

  // Convert messages to YAML
  auto yaml = dynmsg::cpp::message_to_yaml(message);

  dynmsg::cpp::ros_message_destroy_with_allocator(&message, &default_allocator);

  std::map<std::string, bool> field_results_map;
  const auto topic_met = is_topic_condition_met(yaml, topic_condition, field_results_map);
  if (topic_met == subscription.condition) {
    return;
  }
  subscription.condition = topic_met;

  for (const auto & [field_name, field_met] : field_results_map) {
    yaml[field_name] = yaml[field_name].as<std::string>() + (field_met ? " ✅" : " ❌");
  }
  subscription.message = yaml;

  RCLCPP_INFO(
    node_->get_logger(), "Topic condition result: %s\n%s\n%s\n%s\n", topic_met ? "TRUE" : "FALSE",
    topic_name.c_str(), logic_operator_to_string(topic_condition.logic).c_str(),
    YAML::Dump(yaml).c_str());

  const auto global_met = is_global_condition_met();
  if (global_met == global_met_) {
    return;
  }

  global_met_ = global_met;
  notification_.is_condition_met = global_met;
  if (!global_met) {
    notification_.reason = "Conditions are not met";
  } else {
    notification_.reason = "Conditions are met";
  }
  notify();

  RCLCPP_INFO(node_->get_logger(), "Global condition result: %s", global_met ? "TRUE" : "FALSE");
}

void TopicConditionEvaluator::notify()
{
  nlohmann::json json;

  json["logic"] = logic_operator_to_string(topic_config_.logic);

  nlohmann::json topics_json;
  for (const auto & [topic_name, subscription] : subscriptions_) {
    nlohmann::json topic_json;
    if (subscription.condition.has_value()) {
      topic_json["condition"] = subscription.condition.value();
    } else {
      topic_json["condition"] = nullptr;
    }
    topic_json["value"] = yaml_to_json(subscription.message);
    topics_json[topic_name] = topic_json;
  }

  json["topics"] = topics_json;

  notification_.details = json.dump();

  if (callback_) {
    callback_(notification_);
  }
}

nlohmann::json TopicConditionEvaluator::yaml_to_json(const YAML::Node & node) const
{
  if (node.IsScalar()) {
    return node.as<std::string>();
  } else if (node.IsSequence()) {
    nlohmann::json json_array = nlohmann::json::array();
    for (const auto & item : node) {
      json_array.push_back(yaml_to_json(item));
    }
    return json_array;
  } else if (node.IsMap()) {
    nlohmann::json json_object = nlohmann::json::object();
    for (const auto & item : node) {
      json_object[item.first.as<std::string>()] = yaml_to_json(item.second);
    }
    return json_object;
  }

  return nullptr;
}

bool TopicConditionEvaluator::update_received_flags()
{
  bool publisher_exists = false;

  for (auto & [topic_name, subscription] : subscriptions_) {
    if (subscription.generic_subscription) {
      const size_t publisher_count = subscription.generic_subscription->get_publisher_count();
      if (publisher_count == 0) {
        subscription.condition.reset();
      } else {
        publisher_exists = true;
      }
    }
  }

  return publisher_exists;
}

bool TopicConditionEvaluator::is_topic_condition_met(
  const YAML::Node & yaml_node, const TopicCondition & topic_condition,
  std::map<std::string, bool> & field_results_map) const
{
  bool result = false;
  std::vector<bool> field_results;

  field_results_map.clear();

  for (const auto & [field_name, field_condition] : topic_condition.field_conditions) {
    const auto & param = field_condition.value;
    const auto param_type = param.get_type();

    const YAML::Node field_node = yaml_node[field_name];
    if (!field_node) {
      RCLCPP_WARN_THROTTLE(
        node_->get_logger(), *node_->get_clock(), 5000, "Field [%s] not found in message",
        field_name.c_str());
      continue;
    }

    bool field_met = false;
    try {
      switch (param_type) {
        case rclcpp::ParameterType::PARAMETER_BOOL:
          field_met = compare(field_condition.op, field_node.as<bool>(), param.as_bool());
          break;
        case rclcpp::ParameterType::PARAMETER_INTEGER:
          field_met = compare(field_condition.op, field_node.as<int64_t>(), param.as_int());
          break;
        case rclcpp::ParameterType::PARAMETER_DOUBLE:
          field_met = compare(field_condition.op, field_node.as<double>(), param.as_double());
          break;
        case rclcpp::ParameterType::PARAMETER_STRING:
          field_met = compare_or_contains(
            field_condition.op, field_node.as<std::string>(), param.as_string());
          break;
        case rclcpp::ParameterType::PARAMETER_BOOL_ARRAY:
          field_met = compare_or_contains(
            field_condition.op, field_node.as<std::vector<bool>>(), param.as_bool_array());
          break;
        case rclcpp::ParameterType::PARAMETER_INTEGER_ARRAY:
          field_met = compare_or_contains(
            field_condition.op, field_node.as<std::vector<int64_t>>(), param.as_integer_array());
          break;
        case rclcpp::ParameterType::PARAMETER_DOUBLE_ARRAY:
          field_met = compare_or_contains(
            field_condition.op, field_node.as<std::vector<double>>(), param.as_double_array());
          break;
        case rclcpp::ParameterType::PARAMETER_STRING_ARRAY:
          field_met = compare_or_contains(
            field_condition.op, field_node.as<std::vector<std::string>>(), param.as_string_array());
          break;
        case rclcpp::ParameterType::PARAMETER_BYTE_ARRAY:
          field_met = compare_or_contains(
            field_condition.op, field_node.as<std::vector<uint8_t>>(), param.as_byte_array());
          break;
        default:
          RCLCPP_WARN_THROTTLE(
            node_->get_logger(), *node_->get_clock(), 5000, "Unsupported parameter type for [%s]",
            field_name.c_str());
          break;
      }
    } catch (const YAML::Exception & e) {
      RCLCPP_WARN_THROTTLE(
        node_->get_logger(), *node_->get_clock(), 5000, "Failed to parse field [%s]: %s",
        field_name.c_str(), e.what());
    }

    field_results.push_back(field_met);
    field_results_map[field_name] = field_met;
  }

  switch (topic_condition.logic) {
    case LogicOperator::AND:
      result = std::all_of(field_results.begin(), field_results.end(), [](bool v) { return v; });
      break;
    case LogicOperator::OR:
      result = std::any_of(field_results.begin(), field_results.end(), [](bool v) { return v; });
      break;
    default:
      RCLCPP_WARN_THROTTLE(
        node_->get_logger(), *node_->get_clock(), 5000, "Unknown logic type: [%d]",
        static_cast<int>(topic_condition.logic));
      break;
  }

  return result;
}

bool TopicConditionEvaluator::is_global_condition_met() const
{
  bool result = false;
  if (subscriptions_.empty()) return result;

  switch (topic_config_.logic) {
    case LogicOperator::AND:
      // Treat null as true to skip evaluation; it naturally has no effect in an AND condition.
      // !has_value | value | result | description
      // -----------|-------|--------|-------------------------------------
      //  true      |       | true   | no value, right-hand side is skipped
      //  false     | true  | true   | valid and met
      //  false     | false | false  | valid but not met
      result = std::all_of(subscriptions_.begin(), subscriptions_.end(), [](const auto & sub) {
        return !sub.second.condition.has_value() || sub.second.condition.value();
      });
      break;
    case LogicOperator::OR:
      // Treat null as false to skip evaluation; it naturally has no effect in an OR condition.
      // has_value | value | result | description
      // ----------|-------|--------|-------------------------------------
      //  false    |       | false  | no value, right-hand side is skipped
      //  true     | true  | true   | valid and met
      //  true     | false | false  | valid but not met
      result = std::any_of(subscriptions_.begin(), subscriptions_.end(), [](const auto & sub) {
        return sub.second.condition.has_value() && sub.second.condition.value();
      });
      break;
    default:
      RCLCPP_WARN_THROTTLE(
        node_->get_logger(), *node_->get_clock(), 5000, "Unknown logic type: [%d]",
        static_cast<int>(topic_config_.logic));
      break;
  }

  return result;
}

}  // namespace topic_condition_evaluator
