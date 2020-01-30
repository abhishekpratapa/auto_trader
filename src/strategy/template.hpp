#ifndef _STRATEGY_TEMPLATE_
#define _STRATEGY_TEMPLATE_

#include <functional>
#include <vector>

#include <boost/uuid/uuid.hpp>

#include <order/order.hpp>

namespace auto_trader {
namespace strategy {

class StrategyTemplate {
 public:
  StrategyTemplate() = delete;
  StrategyTemplate(float amount) : m_amount(amount){};

  ~StrategyTemplate() = default;

  float get_amount();

  virtual void handle_orders(
      std::function<bool(float price, float amount,
                         enum order::OrderMargin margin,
                         enum order::OrderType type)>
          place,
      std::function<bool(boost::uuids::uuid identifier)> cancel,
      std::vector<std::shared_ptr<order::Order>> orders) = 0;

 protected:
  float m_amount;
};

}  // namespace strategy
}  // namespace auto_trader

#endif