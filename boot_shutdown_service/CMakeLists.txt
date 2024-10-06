cmake_minimum_required(VERSION 3.10.2)
project(boot_shutdown_service)

find_package(Boost REQUIRED COMPONENTS
  serialization
)
find_package(Threads REQUIRED)
find_package(yaml-cpp REQUIRED)

add_library(${PROJECT_NAME} SHARED
  src/boot_shutdown_service.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  Boost::serialization
  Threads::Threads
  yaml-cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../boot_shutdown_internal_msgs/include>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../boot_shutdown_communication/include>"
  "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_internal_msgs>"
  "$<INSTALL_INTERFACE:include/boot_shutdown_communication>"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
  BOOST_ERROR_CODE_HEADER_ONLY
)

add_executable(${PROJECT_NAME}_main
  src/boot_shutdown_main.cpp
)

target_link_libraries(${PROJECT_NAME}_main
  ${PROJECT_NAME}
)

set_target_properties(${PROJECT_NAME}_main PROPERTIES OUTPUT_NAME ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})
install(DIRECTORY cmake/ DESTINATION share/${PROJECT_NAME}/cmake)

install(
  EXPORT export_${PROJECT_NAME}
  DESTINATION share/${PROJECT_NAME}/cmake
  NAMESPACE "${PROJECT_NAME}::"
  FILE "export_${PROJECT_NAME}Export.cmake"
)

install(TARGETS ${PROJECT_NAME}_main
  RUNTIME DESTINATION bin
)
