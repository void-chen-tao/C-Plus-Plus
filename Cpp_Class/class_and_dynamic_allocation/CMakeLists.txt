cmake_minimum_required(VERSION 3.5)
project(test-bad-string)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE debug)

add_executable(test test-bad-string.cpp bad-string.cpp)
target_include_directories(test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)