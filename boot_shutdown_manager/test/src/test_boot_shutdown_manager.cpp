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

#include "gtest/gtest.h"
#include "rclcpp/rclcpp.hpp"
#include "boot_shutdown_manager/boot_shutdown_manager_core.hpp"

using namespace boot_shutdown_manager;

class DummyEcu : public rclcpp::Node
{

  public:
  DummyEcu() : Node("test_dummy_ecu")
  {
    pub_ecu_state_ = create_publisher<EcuState>("/test/get/ecu_state", rclcpp::QoS{1});
    srv_prepare_ = create_service<PrepareShutdown>("/api/test/prepare_shutdown", [this](PrepareShutdown::Request::SharedPtr, PrepareShutdown::Response::SharedPtr){});
    srv_execute_ = create_service<ExecuteShutdown>("/api/test/execute_shutdown", [this](ExecuteShutdown::Request::SharedPtr, ExecuteShutdown::Response::SharedPtr){});

    sub_summary_ = create_subscription<EcuStateSummary>("~/output/ecu_state_summary", rclcpp::QoS{1}, [this](const EcuStateSummary::SharedPtr){});
    cli_shutdown_ = create_client<Shutdown>("~/service/shutdown", rmw_qos_profile_services_default);
  }
  // Sub ECU
  rclcpp::Publisher<EcuState>::SharedPtr pub_ecu_state_;
  rclcpp::Service<PrepareShutdown>::SharedPtr srv_prepare_;
  rclcpp::Service<ExecuteShutdown>::SharedPtr srv_execute_;

  // MOT
  rclcpp::Subscription<EcuStateSummary>::SharedPtr sub_summary_;
  rclcpp::Client<Shutdown>::SharedPtr cli_shutdown_;
};

TEST(boot_shutdown_manager, TestPubSubSrv)
{
  // std::vector<rclcpp::Parameter> params = { rclcpp::Parameter("use_sim_time", true) };
  std::vector<rclcpp::Parameter> params = {{"managed_ecu.test", "default"}};
  rclcpp::NodeOptions node_options;
  node_options.parameter_overrides(params);
  auto manager_ = std::make_shared<BootShutdownManager>(rclcpp::NodeOptions{});
  auto dummy = std::make_shared<DummyEcu>();
}


int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  rclcpp::init(argc, argv);
  bool result = RUN_ALL_TESTS();
  rclcpp::shutdown();
  return result;
}
