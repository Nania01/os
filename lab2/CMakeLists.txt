cmake_minimum_required(VERSION 3.10)
project(ProcessRunnerLab)
set(CMAKE_CXX_STANDARD 17)

add_library(process_runner STATIC process_runner.cpp)
add_executable(TestUtility main.cpp)
target_link_libraries(TestUtility process_runner)