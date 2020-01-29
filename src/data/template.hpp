#ifndef _DATA_TEMPLATE_
#define _DATA_TEMPLATE_

#include <memory>
#include <string>

namespace auto_trader {
namespace data {

struct DataStructure {
  DataStructure() = default;
  virtual ~DataStructure() = default;

  virtual void save(const std::string& path) = 0;

  // TODO: templatize this function to force all base classes to implement a
  // static load
  static std::unique_ptr<DataStructure> loadJSON(const std::string& path);
  static std::unique_ptr<DataStructure> load(const std::string& path);
};

}  // namespace data
}  // namespace auto_trader

#endif