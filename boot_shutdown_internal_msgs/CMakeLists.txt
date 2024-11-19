cmake_minimum_required(VERSION 3.10.2)
project(boot_shutdown_internal_msgs)

find_package(Protobuf REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(PROTO_FILES
  proto/${PROJECT_NAME}/msg/ecu_state_message.proto
  proto/${PROJECT_NAME}/msg/header.proto
  proto/${PROJECT_NAME}/msg/response_status.proto
  proto/${PROJECT_NAME}/srv/execute_shutdown_service.proto
  proto/${PROJECT_NAME}/srv/prepare_shutdown_service.proto
)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_library(${PROJECT_NAME} STATIC ${PROTO_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
  ${Protobuf_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${Protobuf_LIBRARIES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

install(FILES ${PROTO_HDRS} DESTINATION include/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

install(FILES ${PROTO_HDRS} DESTINATION include/${PROJECT_NAME})

install(EXPORT export_${PROJECT_NAME}
  FILE ${PROJECT_NAME}Config.cmake
  DESTINATION lib/cmake/${PROJECT_NAME}
)
