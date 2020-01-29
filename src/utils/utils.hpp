#ifndef _UTILS_UTILS_
#define _UTILS_UTILS_

#include <boost/property_tree/ptree.hpp>
#include <string>

namespace auto_trader {
namespace utils {

boost::property_tree::ptree loadJSON(std::string filename);

// TODO: log progress
// TODO: timing class

}  // namespace utils
}  // namespace auto_trader
#endif
