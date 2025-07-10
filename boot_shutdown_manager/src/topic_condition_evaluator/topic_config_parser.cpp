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

#include "topic_condition_evaluator/topic_config_parser.hpp"

namespace topic_condition_evaluator
{

LogicOperator parse_logic_operator(const std::string & str)
{
  std::string upper = str;
  std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

  if (upper == "AND")
    return LogicOperator::AND;
  else if (upper == "OR")
    return LogicOperator::OR;

  throw std::invalid_argument("Unknown logic operator: " + str);
}

std::string logic_operator_to_string(LogicOperator op)
{
  switch (op) {
    case LogicOperator::AND:
      return "AND";
    case LogicOperator::OR:
      return "OR";
    default:
      return "?";
  }
}

ComparisonOperator parse_comparison_operator(const std::string & str)
{
  std::string lower = str;
  std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

  if (lower == "eq")
    return ComparisonOperator::EQ;
  else if (lower == "ne")
    return ComparisonOperator::NE;
  else if (lower == "le")
    return ComparisonOperator::LE;
  else if (lower == "lt")
    return ComparisonOperator::LT;
  else if (lower == "ge")
    return ComparisonOperator::GE;
  else if (lower == "gt")
    return ComparisonOperator::GT;
  else if (lower == "contains")
    return ComparisonOperator::CONTAINS;
  else if (lower == "not_contains")
    return ComparisonOperator::NOT_CONTAINS;

  throw std::invalid_argument("Unknown comparison operator: " + str);
}

std::string comparison_operator_to_string(ComparisonOperator op)
{
  switch (op) {
    case ComparisonOperator::EQ:
      return "==";
    case ComparisonOperator::NE:
      return "!=";
    case ComparisonOperator::LE:
      return "<=";
    case ComparisonOperator::LT:
      return "<";
    case ComparisonOperator::GE:
      return ">=";
    case ComparisonOperator::GT:
      return ">";
    case ComparisonOperator::CONTAINS:
      return "contains";
    case ComparisonOperator::NOT_CONTAINS:
      return "not_contains";
    default:
      return "?";
  }
}

void print_config(const rclcpp::Node & node, const std::string & param_key, const TopicConfig & config)
{
  std::ostringstream stream;

  stream << "logic: " << logic_operator_to_string(config.logic) << "\n";

  for (const auto & [topic, condition] : config.topic_conditions) {
    stream << "topic: " << topic << "\n";
    stream << "  logic: " << logic_operator_to_string(condition.logic) << "\n";
    for (const auto & [field, cond] : condition.field_conditions) {
      stream << "    " << field << " " << comparison_operator_to_string(cond.op) << " "
             << cond.value.value_to_string() << "\n";
    }
  }

  RCLCPP_INFO(node.get_logger(), "parsed %s:\n%s", param_key.c_str(), stream.str().c_str());
}

TopicConfig parse_config(const rclcpp::Node & node, const std::string & param_key)
{
  TopicConfig config;

  const auto param_names = node.list_parameters({param_key}, 0).names;

  if (param_names.empty()) {
    RCLCPP_INFO(node.get_logger(), "No parameters found: %s", param_key.c_str());
    return config;
  }

  // Loop for the number of topics
  // ex. topic_config.logic
  //     topic_config./vehicle/status/velocity_status.logic
  //     topic_config./vehicle/status/velocity_status.longitudinal_velocity.le
  //     topic_config./vehicle/status/velocity_status.lateral_velocity.le
  for (const auto & param_name : param_names) {
    // Handle global logic parameter: topic_config.logic
    if (param_name == param_key + ".logic") {
      std::string globa_logic = default_logic;
      if (node.get_parameter(param_name, globa_logic)) {
        try {
          config.logic = parse_logic_operator(globa_logic);
        } catch (const std::exception & e) {
          RCLCPP_WARN(
            node.get_logger(), "Invalid operator '%s' in %s", globa_logic.c_str(),
            param_name.c_str());
        }
      }
      continue;
    }

    // Get the part after topic_config.
    // ex. /vehicle/status/velocity_status.logic
    //     /vehicle/status/velocity_status.longitudinal_velocity.le
    const auto prefix = param_key + ".";
    const std::string rest = param_name.substr(prefix.size());

    // Get topic name
    // ex. /vehicle/status/velocity_status
    const auto topic_dot = rest.find('.');
    const auto topic_name = rest.substr(0, topic_dot);

    // Get field name and operator
    // ex. logic
    //     longitudinal_velocity.le
    const auto field_and_op = rest.substr(topic_dot + 1);

    if (field_and_op == "logic") {
      std::string logic = default_logic;
      if (node.get_parameter(param_name, logic)) {
        try {
          config.topic_conditions[topic_name].logic = parse_logic_operator(logic);
        } catch (const std::exception & e) {
          RCLCPP_WARN(
            node.get_logger(), "Invalid operator '%s' in %s", logic.c_str(), param_name.c_str());
        }
      }
      continue;
    }

    const auto second_dot = field_and_op.find('.');
    if (second_dot == std::string::npos) {
      RCLCPP_WARN(
        node.get_logger(), "Invalid parameter format (no operator): %s", param_name.c_str());
      continue;
    }

    // Get field name and operator
    // ex. longitudinal_velocity
    //     le
    const auto field_name = field_and_op.substr(0, second_dot);
    auto op = field_and_op.substr(second_dot + 1);

    rclcpp::Parameter param;
    if (node.get_parameter(param_name, param)) {
      try {
        FieldCondition condition;
        condition.op = parse_comparison_operator(op);
        condition.value = param;
        config.topic_conditions[topic_name].field_conditions[field_name] = condition;
      } catch (const std::exception & e) {
        RCLCPP_WARN(
          node.get_logger(), "Invalid operator '%s' in %s", op.c_str(), param_name.c_str());
        continue;
      }
    }
  }

  print_config(node, param_key, config);

  return config;
}

}  // namespace topic_condition_evaluator
