#include <utils/utils.hpp>

#include <boost/property_tree/json_parser.hpp>

boost::property_tree::ptree auto_trader::utils::loadJSON(std::string filename) {
  boost::property_tree::ptree root;
  boost::property_tree::read_json(filename, root);
  return root;
}
