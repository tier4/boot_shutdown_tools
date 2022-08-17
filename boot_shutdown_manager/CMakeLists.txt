cmake_minimum_required(VERSION 3.14)
project(boot_shutdown_manager)

find_package(autoware_cmake REQUIRED)
autoware_package()

ament_auto_add_library(boot_shutdown_manager
  src/boot_shutdown_manager_core.cpp
)

ament_auto_add_executable(boot_shutdown_manager_node
  src/boot_shutdown_manager_node.cpp
)
target_link_libraries(boot_shutdown_manager_node boot_shutdown_manager)

if(BUILD_TESTING)
  ament_add_ros_isolated_gtest(test_boot_shutdown_manager
    test/src/test_boot_shutdown_manager.cpp
  )
  target_link_libraries(test_boot_shutdown_manager boot_shutdown_manager)
  target_include_directories(test_boot_shutdown_manager PRIVATE include)
  ament_target_dependencies(test_boot_shutdown_manager
    rclcpp
    boot_shutdown_api_msgs
    tier4_api_utils
  )
endif()

ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)
