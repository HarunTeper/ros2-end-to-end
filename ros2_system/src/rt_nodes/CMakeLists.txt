cmake_minimum_required(VERSION 3.5)
project(rt_nodes)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rt_msgs REQUIRED)

include_directories(include)

add_executable(run_system src/main.cpp)

add_library(rtnode SHARED src/rt_node.cpp)

target_include_directories(rtnode PRIVATE src/include)

set(dependencies
  "rclcpp"
  "rt_msgs"
)

ament_target_dependencies(rtnode
  ${dependencies}
)

target_link_libraries(run_system
  rtnode
)

install(TARGETS run_system
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS rtnode
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION include/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

ament_export_include_directories(include)
ament_package()
