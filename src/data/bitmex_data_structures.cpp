#include <data/bitmex_data_structures.hpp>

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.hpp>

using boost::property_tree::ptree;

#define KEY_EXCEPT(expr) \
  try {                  \
    (expr);              \
  } catch (...) {        \
  }

namespace auto_trader {
namespace data {

void BitmexCandleStick::save(const std::string& path) {
  // TODO: write loadJSON
}

std::unique_ptr<BitmexCandleStick> BitmexCandleStick::loadJSON(
    const std::string& path) {
  std::vector<CandleStick_> candleData;
  auto candleSticks = auto_trader::utils::loadJSON(path);

  for (auto e : candleSticks) {
    auto element = e.second;
    CandleStick_ data;

    KEY_EXCEPT(data.foriegn_notional = element.get<double>("foreignNotional"));
    KEY_EXCEPT(data.home_notional = element.get<double>("homeNotional"));

    KEY_EXCEPT(data.open = element.get<double>("open"));
    KEY_EXCEPT(data.close = element.get<double>("close"));

    KEY_EXCEPT(data.high = element.get<double>("high"));
    KEY_EXCEPT(data.low = element.get<double>("low"));
    KEY_EXCEPT(data.vwap = element.get<double>("vwap"));

    KEY_EXCEPT(data.trades = element.get<int64_t>("trades"));
    KEY_EXCEPT(data.turnover = element.get<int64_t>("turnover"));

    KEY_EXCEPT(data.volume = element.get<int64_t>("volume"));

    KEY_EXCEPT(data.last_size = element.get<int64_t>("lastSize"));

    std::string time_string = element.get<std::string>("timestamp");

    int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;
    struct tm breakdown;
    if (sscanf(time_string.c_str(), "%4d-%2d-%2dT%2d:%2d:%2d.000Z", &year,
               &month, &day, &hour, &min, &sec) == 5) {
      breakdown.tm_year = year - 1900;
      breakdown.tm_mon = month - 1;
      breakdown.tm_mday = day;
      breakdown.tm_hour = hour;
      breakdown.tm_min = min;

      data.timestamp = mktime(&breakdown);
    }

    candleData.push_back(data);
  }

  auto instance = std::make_unique<BitmexCandleStick>();
  instance->data = std::move(candleData);

  return instance;
}

std::unique_ptr<BitmexCandleStick> BitmexCandleStick::load(
    const std::string& path) {
  // TODO: write loadJSON
  return std::make_unique<BitmexCandleStick>();
}

}  // namespace data
}  // namespace auto_trader