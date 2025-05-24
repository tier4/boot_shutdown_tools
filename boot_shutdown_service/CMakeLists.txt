cmake_minimum_required(VERSION 3.10.2)
project(boot_shutdown_service)

find_package(boot_shutdown_internal_msgs REQUIRED)
find_package(Threads REQUIRED)
find_package(yaml-cpp REQUIRED)

add_executable(${PROJECT_NAME}
  src/boot_shutdown_main.cpp
  src/boot_shutdown_service.cpp
)

target_link_libraries(${PROJECT_NAME}
  Threads::Threads
  pthread
  yaml-cpp
  boot_shutdown_internal_msgs
)

target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<BUILD_INTERFACE:${CMAKE_INSTALL_PREFIX}/../boot_shutdown_internal_msgs/include>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../boot_shutdown_common/include>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../boot_shutdown_communication/include>"
  "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_internal_msgs>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_common>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_communication>"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
  BOOST_ERROR_CODE_HEADER_ONLY
)

install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})
install(DIRECTORY cmake/ DESTINATION share/${PROJECT_NAME}/cmake)

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
)
