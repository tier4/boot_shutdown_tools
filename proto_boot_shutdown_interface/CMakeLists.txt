cmake_minimum_required(VERSION 3.14)
project(proto_boot_shutdown_interface)

find_package(autoware_cmake REQUIRED)
autoware_package()

ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)

install(PROGRAMS scripts/proto_boot_shutdown_interface_node.py DESTINATION lib/${PROJECT_NAME})

install(FILES DESTINATION share/${PROJECT_NAME})
