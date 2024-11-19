cmake_minimum_required(VERSION 3.14)
project(boot_shutdown_manager)

find_package(ament_cmake_auto REQUIRED)
find_package(boot_shutdown_internal_msgs REQUIRED)

ament_auto_find_build_dependencies()

ament_auto_add_executable(boot_shutdown_manager
  src/boot_shutdown_manager_core.cpp
  src/boot_shutdown_manager_node.cpp
)

target_include_directories(boot_shutdown_manager PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_INSTALL_PREFIX}/../boot_shutdown_internal_msgs/include>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../boot_shutdown_communication/include>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_internal_msgs>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_communication>"
)

target_link_libraries(boot_shutdown_manager
  boot_shutdown_internal_msgs
)

ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)
