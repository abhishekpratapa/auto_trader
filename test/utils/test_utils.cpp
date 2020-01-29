#define BOOST_TEST_MAIN
#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif

#include <filesystem>
#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/filesystem.hpp>

#include <utils/utils.hpp>

#ifdef TEST_FILE_PATH
  static std::string root_test_path = TEST_FILE_PATH;
#else
  static std::string root_test_path = "";
#endif

using auto_trader::utils::loadJSON;

std::vector<std::string> parse_files() {
  std::vector<std::string> json_files;
  for (const auto & entry : boost::filesystem::directory_iterator(root_test_path))
    if (entry.path().filename().string().find(".json") != std::string::npos)
      json_files.push_back(entry.path().string());
  return json_files;
}

BOOST_AUTO_TEST_CASE(test_util_loadJSON) {
  auto json_files = parse_files();
  for (const auto &file : json_files) {
    auto root = loadJSON(file);
  }
  BOOST_ASSERT(true);
}

