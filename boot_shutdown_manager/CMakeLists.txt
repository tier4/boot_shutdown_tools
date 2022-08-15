cmake_minimum_required(VERSION 3.14)
project(boot_shutdown_manager)

find_package(autoware_cmake REQUIRED)
autoware_package()

ament_auto_add_library(boot_shutdown_manager SHARED
  src/boot_shutdown_manager.cpp
)

rclcpp_components_register_node(boot_shutdown_manager
  PLUGIN "boot_shutdown_manager::BootShutdownManager"
  EXECUTABLE boot_shutdown_manager_node
)

ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)
