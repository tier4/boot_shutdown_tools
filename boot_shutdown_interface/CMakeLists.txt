cmake_minimum_required(VERSION 3.14)
project(boot_shutdown_interface)

find_package(ament_cmake_auto REQUIRED)
find_package(Boost REQUIRED COMPONENTS
  serialization
)

ament_auto_find_build_dependencies()

ament_auto_add_library(boot_shutdown_interface_node SHARED
  src/boot_shutdown_interface.cpp
)

target_link_libraries(boot_shutdown_interface_node
  Boost::serialization
  boot_shutdown_service::boot_shutdown_service
)

rclcpp_components_register_node(boot_shutdown_interface_node
  PLUGIN "boot_shutdown_interface::BootShutdownInterface"
  EXECUTABLE boot_shutdown_interface
)

ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)
