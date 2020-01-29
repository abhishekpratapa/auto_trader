cmake_minimum_required(VERSION 3.13.3)
project(AutoTrader_tests)
enable_testing()

add_custom_target(copy_util_example ALL
  COMMAND cmake -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/util_test
                                  ${AT_TESTING_PATH}/util_test
  DEPENDS test_utils.cxxtest
)

add_definitions(-DTEST_FILE_PATH="${AT_TESTING_PATH}/util_test")

add_executable(test_utils.cxxtest
  test_utils.cpp
)

target_link_libraries(test_utils.cxxtest
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  ATUtils
)
