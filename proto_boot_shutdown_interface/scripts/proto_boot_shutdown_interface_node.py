#! /usr/bin/env python3

# Copyright 2022 TIER IV, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import subprocess
import rclpy
from rclpy.node import Node
from boot_shutdown_api_msgs.msg import EcuState
from boot_shutdown_api_msgs.srv import ExecuteShutdown
from boot_shutdown_api_msgs.srv import PrepareShutdown


class ProtoBootShutdownInterfaceNode(Node):
    def __init__(self):
        super().__init__("proto_boot_shutdown")

        self.ecu_name = self.declare_parameter("ecu_name", "ecu").value
        self.startup_timeout = self.declare_parameter("startup_timeout", 180).value
        self.preparation_timeout = self.declare_parameter("preparation_timeout", 180).value

        # Artificial delay for debugging
        self.preparation_delay = self.declare_parameter("debug.preparation_delay", 5).value
        self.shutdown_delay = self.declare_parameter("debug.shutdown_delay", 5).value

        self.ecu_state = EcuState(name=self.ecu_name, state=EcuState.STARTUP)
        self.startup_time = self.get_clock().now()
        self.preparation_process = None

        self.prepare_shutdown_srv = self.create_service(
            PrepareShutdown, "~/service/prepare_shutdown", self.on_prepare_shutdown)

        self.execute_shutdown_srv = self.create_service(
            ExecuteShutdown, "~/service/execute_shutdown", self.on_execute_shutdown)

        self.ecu_state_pub = self.create_publisher(EcuState, "~/output/ecu_state", 1)

        self.timer = self.create_timer(1.0, self.on_timer)

    def on_prepare_shutdown(self, request, response):
        self.get_logger().info("shutdown preparing...")
        try:
            # Clear pagecache, dentries, and inodes.
            self.preparation_process = subprocess.Popen(
                f"sync; echo 3 > /proc/sys/vm/drop_caches; sleep {self.preparation_delay}", shell=True)
            self.ecu_state.state = EcuState.SHUTDOWN_PREPARING
            self.preparation_start_time = self.get_clock().now()
        except:
            # Prevention of node crash
            # subprocess can fail in some cases (e.g., no authorization)
            pass

        response.status.success = True
        response.power_off_time = (self.get_clock().now() +
                                   rclpy.duration.Duration(seconds=10)).to_msg()
        return response

    def on_execute_shutdown(self, request, response):
        self.get_logger().info("shutdown executing...")
        try:
            # Shutdown
            # Avoid using "now" and delay shutdown to publish ecu_state
            self.shutdown_process = subprocess.Popen(f"shutdown -h -t {self.shutdown_delay}", shell=True)
        except:
            pass
        
        power_off_time = (self.get_clock().now() + rclpy.duration.Duration(seconds=self.shutdown_delay)).to_msg()
        self.ecu_state.power_off_time = power_off_time
        response.status.success = True
        response.power_off_time = power_off_time
        return response

    def on_timer(self):
        if self.ecu_state.state == EcuState.STARTUP:
            if self._is_running():
                self.ecu_state.state = EcuState.RUNNING
            elif self._startup_timeout():
                self.ecu_state.state = EcuState.STARTUP_TIMEOUT
        elif self.ecu_state.state == EcuState.SHUTDOWN_PREPARING:
            if self._is_ready():
                self.ecu_state.state = EcuState.SHUTDOWN_READY
            elif self._preparation_timeout():
                self.ecu_state.state = EcuState.SHUTDOWN_TIMEOUT

        self.ecu_state_pub.publish(self.ecu_state)

    def _is_running(self):
        # implement process to check for startup
        return True

    def _startup_timeout(self):
        is_timeout = (self.get_clock().now() -
                      self.startup_time) > rclpy.duration.Duration(seconds=self.startup_timeout)
        return is_timeout

    def _preparation_timeout(self):
        is_timeout = (self.get_clock().now(
        ) - self.preparation_start_time) > rclpy.duration.Duration(seconds=self.preparation_timeout)
        return is_timeout

    def _is_ready(self):
        poll = self.preparation_process.poll()
        return poll is not None


def main(args=None):
    rclpy.init(args=args)

    node = ProtoBootShutdownInterfaceNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
