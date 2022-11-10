cmake_minimum_required(VERSION 3.14)
project(boot_shutdown_manager)

find_package(ament_cmake_auto REQUIRED)

ament_auto_find_build_dependencies()


ament_auto_add_executable(boot_shutdown_manager
  src/boot_shutdown_manager_core.cpp
  src/boot_shutdown_manager_node.cpp
)

ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)
