#define BOOST_TEST_MAIN
#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif

#include <iostream>

#include <filesystem>
#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/filesystem.hpp>

#include <data/bitmex_data.hpp>

#ifdef TEST_FILE_PATH
  static std::string root_test_path = TEST_FILE_PATH;
#else
  static std::string root_test_path = "";
#endif

using auto_trader::data::BitmexCandleStick;

BOOST_AUTO_TEST_CASE(test_data_loadCandleStick) {
  auto json_file = root_test_path + "/candle_data.json";
  auto parsed_data = BitmexCandleStick::loadJSON(json_file);
  BOOST_ASSERT(true);
}
