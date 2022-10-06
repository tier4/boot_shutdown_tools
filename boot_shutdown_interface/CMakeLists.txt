cmake_minimum_required(VERSION 3.14)
project(boot_shutdown_interface)

find_package(ament_cmake_auto REQUIRED)
find_package(Boost REQUIRED COMPONENTS
  filesystem
)

ament_auto_find_build_dependencies()

ament_auto_add_executable(boot_shutdown_interface
  src/boot_shutdown_interface_core.cpp
  src/boot_shutdown_interface_node.cpp
)

ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)
