cmake_minimum_required(VERSION 3.5)
project(example)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(foo)

add_executable(main main.cc)
target_include_directories(main PRIVATE foo)
target_link_libraries(main PRIVATE foo)
