cmake_minimum_required(VERSION 3.13.3)
project(AutoTrader_tests)
enable_testing()

set(EXECUTABLE_OUTPUT_PATH ${AT_TESTING_PATH})

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(data)
add_subdirectory(utils)
