cmake_minimum_required(VERSION 3.10.2)
project(boot_shutdown_service)

find_program(ROS2 "ros2")
if (ROS2)
 include(CMakeLists.ros2)
else()
 include(CMakeLists.noros2)
endif()
