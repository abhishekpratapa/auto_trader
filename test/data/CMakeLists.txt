cmake_minimum_required(VERSION 3.13.3)
project(AutoTrader_tests)
enable_testing()

add_custom_target(copy_data_example ALL
  COMMAND cmake -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/data_test
                                  ${AT_TESTING_PATH}/data_test
  DEPENDS test_data.cxxtest
)

add_definitions(-DTEST_FILE_PATH="${AT_TESTING_PATH}/data_test")

add_executable(test_data.cxxtest
  test_data.cpp
)

target_link_libraries(test_data.cxxtest
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  ATData
)
