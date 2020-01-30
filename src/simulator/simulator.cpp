#include <simulator/simulator.hpp>

#include <functional>

namespace auto_trader {
namespace simulator {

Simulator::Simulator(
    std::shared_ptr<strategy::StrategyTemplate> strategy,
    std::shared_ptr<pricing::PricingTemplate> pricing)
    : m_strategy(strategy), m_pricing(pricing) {}


bool Simulator::cancel_order(boost::uuids::uuid identifier) {
	// TODO: cancel order or return false
  return true;
}
 
bool Simulator::place_order(float price, float amount, enum order::OrderMargin margin, enum order::OrderType type){
  // TODO: place order or return false
  return true;
}

void Simulator::step() {
  auto place_function = [&](float price, float amount, enum order::OrderMargin margin, enum order::OrderType type) {
    return this->place_order(price, amount, margin, type);
  };

  auto cancel_function = [&](boost::uuids::uuid identifier) {
    return this->cancel_order(identifier);
  };

  m_strategy->handle_orders(place_function, cancel_function, m_orders);
}

void Simulator::start() {
  // TODO: continue until end of price cycle or strategy gets to 0 amount
}

float Simulator::roi() {
  if(m_roi.size() > 0) {
    return m_roi.back().second;
  }

  return 0.0;
}

std::vector<std::pair<size_t, float>> Simulator::roi_curve() {
  return m_roi;
}

}  // namespace simulator
}  // namespace auto_trader