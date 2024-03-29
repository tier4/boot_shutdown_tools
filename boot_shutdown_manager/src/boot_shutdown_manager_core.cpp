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

#include "boot_shutdown_manager/boot_shutdown_manager_core.hpp"

#define FMT_HEADER_ONLY
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

template <typename ServiceT>
typename ServiceT::Response::SharedPtr call(
  const std::shared_ptr<rclcpp::Client<ServiceT>> client,
  const typename ServiceT::Request::SharedPtr & request,
  const std::chrono::nanoseconds & timeout = std::chrono::seconds(2))
{
  if (!client->service_is_ready()) {
    return nullptr;
  }

  auto future = client->async_send_request(request);
  if (future.wait_for(timeout) != std::future_status::ready) {
    return nullptr;
  }
  return future.get();
}

}  // namespace

namespace boot_shutdown_manager
{

BootShutdownManager::BootShutdownManager()
: Node(
    "boot_shutdown_manager",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
{
  using std::placeholders::_1;
  using std::placeholders::_2;

  get_parameter_or("update_rate", update_rate_, 1.0);
  get_parameter_or("startup_timeout", startup_timeout_, 300.0);
  get_parameter_or("preparation_timeout", preparation_timeout_, 60.0);

  ecu_state_summary_.summary.state = EcuState::STARTUP;
  last_transition_stamp_ = now();
  is_shutting_down = false;
  is_force_shutdown_ = false;
  callback_group_ = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

  pub_ecu_state_summary_ =
    create_publisher<EcuStateSummary>("~/output/ecu_state_summary", rclcpp::QoS{1});
  srv_shutdown = create_service<Shutdown>(
    "~/service/shutdown", std::bind(&BootShutdownManager::onShutdownService, this, _1, _2),
    rmw_qos_profile_default, callback_group_);
  srv_force_shutdown_ = create_service<Shutdown>(
    "~/service/force_shutdown", std::bind(&BootShutdownManager::onForceShutdownService, this, _1, _2),
    rmw_qos_profile_default, callback_group_);

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
    bool skip_shutdown;
    bool primary;

    this->get_parameter_or(param_prefix + "primary", primary, false);
    this->get_parameter_or(param_prefix + "skip_shutdown", skip_shutdown, false);
    this->get_parameter_or(
      param_prefix + "state", state_topic_name, fmt::format("/{}/get/ecu_state", ecu_name));
    this->get_parameter_or(
      param_prefix + "prepare", prepare_service_name,
      fmt::format("/api/{}/prepare_shutdown", ecu_name));
    this->get_parameter_or(
      param_prefix + "execute", execute_service_name,
      fmt::format("/api/{}/execute_shutdown", ecu_name));

    auto client = std::make_shared<EcuClient>();
    {
      client->skip_shutdown = skip_shutdown;
      client->cli_execute = create_client<ExecuteShutdown>(
        execute_service_name, rmw_qos_profile_services_default, callback_group_);
      client->cli_prepare =
        create_client<PrepareShutdown>(prepare_service_name, rmw_qos_profile_services_default);
      client->sub_ecu_state = create_subscription<EcuState>(
        state_topic_name, rclcpp::QoS{1},
        [this, client](const EcuState::SharedPtr msg) { client->ecu_state = msg; });
      client->ecu_state = std::make_shared<EcuState>();
      client->ecu_state->state = EcuState::UNKNOWN;
      client->ecu_state->name = ecu_name;
    }
    if(client->primary){
      ecu_client_queue_.push_back({ecu_name, client});
    }else{
      ecu_client_queue_.push_front({ecu_name, client});
    }


    cli_webauto_ = create_client<std_srvs::srv::SetBool>(
      "/webauto/shutdown", rmw_qos_profile_services_default, callback_group_);

    RCLCPP_INFO(
      get_logger(),
      fmt::format("start monitoring : {}", ecu_name + (skip_shutdown ? "*" : "")).c_str());
  }

  const auto period_ns = rclcpp::Rate(update_rate_).period();
  timer_ = rclcpp::create_timer(
    this, get_clock(), period_ns, std::bind(&BootShutdownManager::onTimer, this));
}

void BootShutdownManager::onShutdownService(
  Shutdown::Request::SharedPtr, Shutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "PrepareShutdown start");
  auto req = std::make_shared<PrepareShutdown::Request>();
  for (auto & [ecu_name, client] : ecu_client_queue_) {
    if (client->skip_shutdown) {
      continue;
    }
    auto resp = call<PrepareShutdown>(client->cli_prepare, req);
    if (!resp) {
      RCLCPP_WARN(get_logger(), "[%s] PrepareShutdown service call faild.", ecu_name.c_str());
    }
  }

  {
    auto req = std::make_shared<std_srvs::srv::SetBool::Request>();
    req->data = true;
    auto resp = call<std_srvs::srv::SetBool>(cli_webauto_, req);
    if (!resp) {
      RCLCPP_WARN(get_logger(), "webauto shutdown service call faild.");
    }
  }

  ecu_state_summary_.summary.state = EcuState::SHUTDOWN_PREPARING;
  last_transition_stamp_ = now();
  RCLCPP_INFO(get_logger(), "state transioned : -> SHUTDOWN_PREPARING");

  response->status.success = true;
}

void BootShutdownManager::onForceShutdownService(
  Shutdown::Request::SharedPtr request, Shutdown::Response::SharedPtr response)
{
  RCLCPP_INFO(get_logger(), "ForceShutdown start");

  onShutdownService(request, response);

  // Enforce notification of SHUTDOWN_PREPARING
  pub_ecu_state_summary_->publish(ecu_state_summary_);

  is_force_shutdown_ = true;

  response->status.success = true;
}

void BootShutdownManager::onTimer()
{
  // Update summary
  auto & summary = ecu_state_summary_.summary;

  if (summary.state == EcuState::STARTUP || summary.state == EcuState::STARTUP_TIMEOUT) {
    if (isRunning()) {
      summary.state = EcuState::RUNNING;
      last_transition_stamp_ = now();
      RCLCPP_INFO(get_logger(), "state transioned : -> RUNNING");
    } else if (
      (now() - last_transition_stamp_) > rclcpp::Duration::from_seconds(startup_timeout_)) {
      summary.state = EcuState::STARTUP_TIMEOUT;
    }
  } else if (
    summary.state == EcuState::SHUTDOWN_PREPARING || summary.state == EcuState::SHUTDOWN_TIMEOUT) {
    if (isReady()) {
      summary.state = EcuState::SHUTDOWN_READY;

      rclcpp::Time last_power_off_time = now();
      for (auto & [ecu_name, client] : ecu_client_queue_) {
        if (client->skip_shutdown) {
          continue;
        }
        rclcpp::Time power_off_time = client->ecu_state->power_off_time;
        if (last_power_off_time < power_off_time) {
          last_power_off_time = power_off_time;
        }
      }
      summary.power_off_time = last_power_off_time;
      last_transition_stamp_ = now();
      RCLCPP_INFO(get_logger(), "state transioned : -> SHUTDOWN_READY");
    } else if (
      (now() - last_transition_stamp_) > rclcpp::Duration::from_seconds(preparation_timeout_)) {
      summary.state = EcuState::SHUTDOWN_TIMEOUT;
      // Enable the next forced shutdown
      is_shutting_down = false;
    }
  } else if (summary.state == EcuState::SHUTDOWN_READY) {
    if (!is_shutting_down) {
      executeShutdown();
    }
  }

  // Update detail
  ecu_state_summary_.details.clear();
  for (auto & [ecu_name, client] : ecu_client_queue_) {
    ecu_state_summary_.details.push_back(*client->ecu_state);
  }

  pub_ecu_state_summary_->publish(ecu_state_summary_);
}

bool BootShutdownManager::isRunning() const
{
  for (const auto & [ecu_name, client] : ecu_client_queue_) {
    if (client->ecu_state->state != EcuState::RUNNING) {
      return false;
    }
  }
  return true;
}

bool BootShutdownManager::isReady() const
{
  // Ignore the states of ECUs during forced shutdown
  if (is_force_shutdown_) {
    return true;
  }

  for (const auto & [ecu_name, client] : ecu_client_queue_) {
    if (client->skip_shutdown) {
      continue;
    }
    if (client->ecu_state->state != EcuState::SHUTDOWN_READY) {
      return false;
    }
  }
  return true;
}

void BootShutdownManager::executeShutdown()
{
  RCLCPP_INFO(get_logger(), "ExecuteShutdown start");
  rclcpp::Time latest_power_off_time = now();
  auto req = std::make_shared<ExecuteShutdown::Request>();
  for (auto & [ecu_name, client] : ecu_client_queue_) {
    if (client->skip_shutdown) {
      continue;
    }
    auto resp = call<ExecuteShutdown>(client->cli_execute, req);
    if (!resp) {
      RCLCPP_WARN(get_logger(), "[%s] ExecuteShutdown service call faild.", ecu_name.c_str());
      // Prevent process ressart due to null access when ECU is not running
      continue;
    }
    rclcpp::Time power_off_time = resp->power_off_time;
    if (latest_power_off_time < power_off_time) {
      latest_power_off_time = power_off_time;
    }
  }
  is_shutting_down = true;
  ecu_state_summary_.summary.power_off_time = latest_power_off_time;
}

}  // namespace boot_shutdown_manager
