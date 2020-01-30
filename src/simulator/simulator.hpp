#ifndef _SIMULATOR_SIMULATOR_TEMPLATE_
#define _SIMULATOR_SIMULATOR_TEMPLATE_

#include <utility>
#include <memory>
#include <vector>

#include <boost/uuid/uuid.hpp>

#include <order/order.hpp>
#include <pricing/template.hpp>
#include <strategy/template.hpp>

namespace auto_trader {
namespace simulator {

class Simulator {
 public:
  Simulator() = delete;
  Simulator(std::shared_ptr<strategy::StrategyTemplate> strategy,
            std::shared_ptr<pricing::PricingTemplate> pricing);
  ~Simulator() = default;

  bool cancel_order(boost::uuids::uuid identifier);
  bool place_order(float price, float amount, enum order::OrderMargin margin, enum order::OrderType type);

  void step();
  void start();
  
  float roi();
  std::vector<std::pair<size_t, float>> roi_curve();
 private:
  std::shared_ptr<strategy::StrategyTemplate> m_strategy;
  std::shared_ptr<pricing::PricingTemplate> m_pricing;
  std::vector<std::shared_ptr<order::Order>> m_orders;

  std::vector<std::pair<size_t, float>> m_roi;
};

}  // namespace simulator
}  // namespace auto_trader

#endif