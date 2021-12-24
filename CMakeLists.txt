cmake_minimum_required(VERSION 3.20)
project(cicd)

set(CMAKE_CXX_STANDARD 14)

add_executable(cicd main.cpp)
add_subdirectory(lib/googletest-release-1.11.0)
include_directories(lib/googletest-release-1.11.0/googletest/include)
target_link_libraries(cicd gtest_main)