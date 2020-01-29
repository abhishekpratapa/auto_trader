cmake_minimum_required(VERSION 3.13.3)
project(AutoTrader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(AT_APPLICATION_PATH ${PROJECT_SOURCE_DIR}/target/applications)
set(AT_TESTING_PATH ${PROJECT_SOURCE_DIR}/target/tests)
set(AT_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/target/libs)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test)
