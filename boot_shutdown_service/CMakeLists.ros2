cmake_minimum_required(VERSION 3.14)
project(boot_shutdown_service)

find_package(ament_cmake_auto REQUIRED)
find_package(Boost REQUIRED COMPONENTS
  serialization
  system
)

ament_auto_find_build_dependencies()

ament_auto_add_executable(boot_shutdown_service
  src/boot_shutdown_main.cpp
  src/boot_shutdown_service.cpp
)

target_link_libraries(boot_shutdown_service ${Boost_LIBRARIES} pthread)

ament_auto_package()
