#ifndef _SIMULATOR_BITMEX_DATA_STRUCTURES_
#define _SIMULATOR_BITMEX_DATA_STRUCTURES_

#include <ctime>
#include <memory>
#include <vector>

#include <data/template.hpp>

namespace auto_trader {
namespace data {

struct CandleStick_ {
  double foriegn_notional;
  double home_notional;

  double open;
  double close;

  double high;
  double low;
  double vwap;

  int64_t trades;
  int64_t turnover;
  int64_t volume;
  int64_t last_size;

  std::time_t timestamp;
};

struct BitmexCandleStick : DataTemplate {
  std::vector<CandleStick_> data;

  void save(const std::string& path) override;

  // TODO: templatize load to force load for all DataStructures
  static std::unique_ptr<BitmexCandleStick> loadJSON(const std::string& path);
  static std::unique_ptr<BitmexCandleStick> load(const std::string& path);
};

}  // namespace data
}  // namespace auto_trader

#endif
