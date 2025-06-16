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

#ifndef TOPIC_CONDITION_EVALUATOR__TOPIC_CONFIG_HPP_
#define TOPIC_CONDITION_EVALUATOR__TOPIC_CONFIG_HPP_

#include <rclcpp/rclcpp.hpp>

#include <map>
#include <string>

namespace topic_condition_evaluator
{

enum class LogicOperator { AND, OR };
enum class ComparisonOperator { EQ, NE, LE, LT, GE, GT, CONTAINS, NOT_CONTAINS };

struct FieldCondition
{
  ComparisonOperator op;
  rclcpp::Parameter value;
};

struct TopicCondition
{
  LogicOperator logic;
  std::map<std::string, FieldCondition> field_conditions;
};

struct TopicConfig
{
  LogicOperator logic;
  std::map<std::string, TopicCondition> topic_conditions;
};

template <typename T>
bool compare(ComparisonOperator op, const T & lhs, const T & rhs)
{
  switch (op) {
    case ComparisonOperator::EQ:
      return lhs == rhs;
    case ComparisonOperator::NE:
      return lhs != rhs;
    case ComparisonOperator::LT:
      return lhs < rhs;
    case ComparisonOperator::LE:
      return lhs <= rhs;
    case ComparisonOperator::GT:
      return lhs > rhs;
    case ComparisonOperator::GE:
      return lhs >= rhs;
    default:
      return false;
  }
}

inline bool contains_impl(const std::string & lhs, const std::string & rhs)
{
  return lhs.find(rhs) != std::string::npos;
}

template <typename T>
bool contains_impl(const std::vector<T> & lhs, const std::vector<T> & rhs)
{
  return std::any_of(rhs.begin(), rhs.end(), [&](const T & val) {
    return std::find(lhs.begin(), lhs.end(), val) != lhs.end();
  });
}

template <typename T>
bool compare_or_contains(ComparisonOperator op, const T & lhs, const T & rhs)
{
  switch (op) {
    case ComparisonOperator::CONTAINS:
      return contains_impl(lhs, rhs);
    case ComparisonOperator::NOT_CONTAINS:
      return !contains_impl(lhs, rhs);
    default:
      return compare(op, lhs, rhs);
  }
}

}  // namespace topic_condition_evaluator

#endif  // TOPIC_CONDITION_EVALUATOR__TOPIC_CONFIG_HPP_
