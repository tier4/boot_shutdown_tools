cmake_minimum_required(VERSION 3.10.2)
project(boot_shutdown_internal_msgs)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)

target_compile_definitions(${PROJECT_NAME} INTERFACE
  BOOST_ERROR_CODE_HEADER_ONLY
)

install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})

install(
  EXPORT export_${PROJECT_NAME}
  DESTINATION share/${PROJECT_NAME}/cmake
  NAMESPACE "${PROJECT_NAME}::"
  FILE "export_${PROJECT_NAME}Export.cmake"
)
