// Copyright 2022 TIER IV, Inc.
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

#include "boot_shutdown_manager/boot_shutdown_manager.hpp"

#include <fmt/format.h>

namespace
{
std::vector<std::string> split(const std::string & str, const char delim)
{
  std::vector<std::string> elems;
  std::stringstream ss(str);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}
}  // namespace

namespace boot_shutdown_manager
{

BootShutdownManager::BootShutdownManager(rclcpp::NodeOptions node_options)
: Node("boot_shutdown_manager", node_options.automatically_declare_parameters_from_overrides(true))
{
  using std::placeholders::_1;
  using std::placeholders::_2;

  auto update_rate = declare_parameter("update_rate", 1.0);

  ecu_state_summary_.summary.state = EcuState::STARTUP;
  last_transition_stamp_ = now();
  is_shutting_down = false;

  pub_ecu_state_summary_ =
    create_publisher<EcuStateSummary>("/pilot_auto/api/ecu_state", rclcpp::QoS{1});
  srv_shutdown = create_service<Shutdown>(
    "/pilot_auto/api/ecu/shutdown",
    std::bind(&BootShutdownManager::onShutdownService, this, _1, _2));

  std::set<std::string> ecu_names;
  const auto param_names = list_parameters({"managed_ecu"}, 3).names;
  for (const auto & param_name : param_names) {
    const auto split_names = split(param_name, '.');
    const auto category_name = split_names[0];
    const auto ecu_name = split_names[1];
    const auto param_prefix = fmt::format("{}.{}.", category_name, ecu_name);

    // Skip duplicate parameter
    if (ecu_names.count(ecu_name) > 0) {
      continue;
    }
    ecu_names.insert(ecu_name);

    std::string state_topic_name;
    std::string prepare_service_name;
    std::string execute_service_name;
    bool is_primary;

    this->get_parameter_or(param_prefix + "primary", is_primary, false);
    this->get_parameter_or(
      param_prefix + "state", state_topic_name, fmt::format("/{}/get/ecu_state", ecu_name));
    this->get_parameter_or(
      param_prefix + "prepare", prepare_service_name,
      fmt::format("/api/{}/prepare_shutdown", ecu_name));
    this->get_parameter_or(
      param_prefix + "execute", execute_service_name,
      fmt::format("/api/{}/execute_shutdown", ecu_name));

    // Debug
    std::cout << fmt::format(
                   "{}:\n  {}\n  {}\n  {}", ecu_name, state_topic_name, prepare_service_name,
                   execute_service_name)
              << std::endl;

    auto client = std::make_shared<EcuClient>();
    {
      client->is_primary = is_primary;
      client->cli_execute =
        create_client<ExecuteShutdown>(execute_service_name, rmw_qos_profile_services_default);
      client->cli_prepare =
        create_client<PrepareShutdown>(prepare_service_name, rmw_qos_profile_services_default);
      client->sub_ecu_state = create_subscription<EcuState>(
        state_topic_name, rclcpp::QoS{1},
        [this, client](const EcuState::SharedPtr msg) { client->ecu_state = msg; });
    }
    ecu_client_map_.insert({ecu_name, client});
  }

  const auto period_ns = rclcpp::Rate(update_rate).period();
  timer_ = rclcpp::create_timer(
    this, get_clock(), period_ns, std::bind(&BootShutdownManager::onTimer, this));
}

void BootShutdownManager::onShutdownService(
  Shutdown::Request::SharedPtr, Shutdown::Response::SharedPtr response)
{
  auto req = std::make_shared<PrepareShutdown::Request>();
  for (auto & [ecu_name, client] : ecu_client_map_) {
    if (client->cli_prepare->service_is_ready()) {
      client->cli_prepare->async_send_request(req);
    }
  }

  ecu_state_summary_.summary.state = EcuState::SHUTDOWN_PREPARING;
  last_transition_stamp_ = now();

  response->status.success = true;
}

void BootShutdownManager::onTimer()
{
  // Update summary
  auto & summary = ecu_state_summary_.summary;
  switch (summary.state) {
    case EcuState::STARTUP:
      if (isRunning()) {
        summary.state = EcuState::RUNNING;
        last_transition_stamp_ = now();
      } else if ((last_transition_stamp_ - now()) > rclcpp::Duration::from_seconds(300)) {
        summary.state = EcuState::STARTUP_TIMEOUT;
      }
      break;
    case EcuState::RUNNING:
      break;
    case EcuState::SHUTDOWN_PREPARING:
      if (isReady()) {
        summary.state = EcuState::SHUTDOWN_READY;
        last_transition_stamp_ = now();
      } else if ((last_transition_stamp_ - now()) > rclcpp::Duration::from_seconds(300)) {
        summary.state = EcuState::SHUTDOWN_TIMEOUT;
      }
      break;
    case EcuState::SHUTDOWN_READY:
      if(!is_shutting_down){
        executeShutdown();
      }
      break;
    default:
      break;
  }

  // Update detail
  ecu_state_summary_.details.clear();
  for (auto & [ecu_name, client] : ecu_client_map_) {
    if (client->ecu_state) {
      ecu_state_summary_.details.push_back(*client->ecu_state);
    }
  }

  pub_ecu_state_summary_->publish(ecu_state_summary_);
}

bool BootShutdownManager::isRunning()
{
  for (auto & [ecu_name, client] : ecu_client_map_) {
    if (!client->ecu_state || client->ecu_state->state != EcuState::RUNNING) {
      return false;
    }
  }
  return true;
}

bool BootShutdownManager::isReady()
{
  for (auto & [ecu_name, client] : ecu_client_map_) {
    if (!client->ecu_state || client->ecu_state->state != EcuState::SHUTDOWN_READY) {
      return false;
    }
  }
  return true;
}

void BootShutdownManager::executeShutdown()
{
  rclcpp::Time latest_power_off_time = now();
  auto req = std::make_shared<ExecuteShutdown::Request>();
  for (auto & [ecu_name, client] : ecu_client_map_) {
    if (client->cli_prepare->service_is_ready()) {
      auto future = client->cli_execute->async_send_request(req);
      if (future.wait_for(std::chrono::seconds(3)) != std::future_status::ready) {
        // timeout
      }
      auto power_off_time = future.get()->power_off_time;
      if(latest_power_off_time < power_off_time){
        latest_power_off_time = power_off_time;
      }
    }
  }
  is_shutting_down = true;
  ecu_state_summary_.summary.power_off_time = latest_power_off_time;
}

}  // namespace boot_shutdown_manager
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(boot_shutdown_manager::BootShutdownManager)
