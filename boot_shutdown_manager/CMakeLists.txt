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


ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)
