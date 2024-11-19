cmake_minimum_required(VERSION 3.10.2)
project(localhost_shutdown)

find_package(boot_shutdown_internal_msgs REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}
  src/localhost_shutdown.cpp
  src/localhost_shutdown_main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<BUILD_INTERFACE:${CMAKE_INSTALL_PREFIX}/../boot_shutdown_internal_msgs/include>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../boot_shutdown_communication/include>"
  "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_internal_msgs>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_communication>"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
  BOOST_ERROR_CODE_HEADER_ONLY
)

target_link_libraries(${PROJECT_NAME}
  Threads::Threads
  pthread
  boot_shutdown_internal_msgs
)

install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  RUNTIME DESTINATION bin
)
