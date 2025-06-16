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

#ifndef TOPIC_CONDITION_EVALUATOR__TOPIC_CONFIG_PARSER_HPP_
#define TOPIC_CONDITION_EVALUATOR__TOPIC_CONFIG_PARSER_HPP_

#include "topic_condition_evaluator/topic_config.hpp"

#include <rclcpp/rclcpp.hpp>

namespace topic_condition_evaluator
{

static constexpr const char * default_logic = "AND";

TopicConfig parse_config(const rclcpp::Node & node, const std::string & param_key);
std::string logic_operator_to_string(LogicOperator op);
std::string comparison_operator_to_string(ComparisonOperator op);

}  // namespace topic_condition_evaluator

#endif  // TOPIC_CONDITION_EVALUATOR__TOPIC_CONFIG_PARSER_HPP_
