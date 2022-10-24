cmake_minimum_required(VERSION 3.14)
project(boot_shutdown_interface)

find_package(ament_cmake_auto REQUIRED)
find_package(Boost REQUIRED COMPONENTS
  serialization
  system
)

ament_auto_find_build_dependencies()

ament_auto_add_executable(boot_shutdown_interface
  src/boot_shutdown_interface_core.cpp
  src/boot_shutdown_interface_node.cpp
)

ament_auto_add_executable(boot_shutdown_service
  src/service/boot_shutdown_main.cpp
  src/service/boot_shutdown_service.cpp
)

ament_auto_add_library(boot_shutdown_guest_lib SHARED
  src/boot_shutdown_guest.cpp
)

target_link_libraries(boot_shutdown_interface ${Boost_LIBRARIES})
target_link_libraries(boot_shutdown_service ${Boost_LIBRARIES})
target_link_libraries(boot_shutdown_guest_lib ${Boost_LIBRARIES})

rclcpp_components_register_node(boot_shutdown_guest_lib
  PLUGIN "boot_shutdown_interface::BootShutdownGuest"
  EXECUTABLE boot_shutdown_guest
)

ament_auto_package(
  INSTALL_TO_SHARE
    config
    launch
)
