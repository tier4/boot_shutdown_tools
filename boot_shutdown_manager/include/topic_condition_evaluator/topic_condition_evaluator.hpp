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

#ifndef TOPIC_CONDITION_EVALUATOR__TOPIC_CONDITION_EVALUATOR_HPP_
#define TOPIC_CONDITION_EVALUATOR__TOPIC_CONDITION_EVALUATOR_HPP_

#include "topic_condition_evaluator/topic_config.hpp"

#include <dynmsg/typesupport.hpp>
#include <nlohmann/json.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/serialization.hpp>

#include <yaml-cpp/yaml.h>

namespace topic_condition_evaluator
{

struct Subscription
{
  rclcpp::GenericSubscription::SharedPtr generic_subscription;
  std::shared_ptr<rclcpp::SerializationBase> serialization_base;
  std::optional<bool> condition;
  YAML::Node message;
};

struct ConditionNotification
{
  std::optional<bool> is_condition_met;
  std::string reason;
  std::string details;
};

class TopicConditionEvaluator
{
public:
  using ConditionNotificationCallback = std::function<void(const ConditionNotification &)>;

  void setup(
    rclcpp::Node * node, const std::string & topic_config_param_key,
    const std::string & qos_profile_path_param_key, ConditionNotificationCallback callback);

  TopicConditionEvaluator();
  TopicConditionEvaluator(const TopicConditionEvaluator &) = delete;
  TopicConditionEvaluator & operator=(const TopicConditionEvaluator &) = delete;
  TopicConditionEvaluator(TopicConditionEvaluator &&) = delete;
  TopicConditionEvaluator & operator=(TopicConditionEvaluator &&) = delete;

private:
  void on_timer();
  void on_subscription_timer();

  bool create_generic_subscriptions();
  rclcpp::QoS create_qos_from_yaml(const YAML::Node & qos_node) const;
  void generic_subscription_callback(
    std::shared_ptr<rclcpp::SerializedMessage> msg, const std::string & topic_name,
    const TopicCondition & topic_condition, Subscription & subscription,
    const TypeInfo_Cpp * dynmsg_typeinfo);

  void notify();
  nlohmann::json yaml_to_json(const YAML::Node & node) const;
  bool update_received_flags();

  bool is_topic_condition_met(
    const YAML::Node & yaml_node, const TopicCondition & topic_condition,
    std::map<std::string, bool> & field_results_map) const;
  bool is_global_condition_met() const;

  rclcpp::Node * node_;
  ConditionNotificationCallback callback_;

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::TimerBase::SharedPtr subscription_timer_;

  std::string qos_profile_path_;
  TopicConfig topic_config_;
  ConditionNotification notification_;

  YAML::Node qos_profile_;
  std::map<std::string, Subscription> subscriptions_;
  std::optional<bool> global_met_;
};

}  // namespace topic_condition_evaluator

#endif  // TOPIC_CONDITION_EVALUATOR__TOPIC_CONDITION_EVALUATOR_HPP_
