#include <order/order.hpp>

namespace auto_trader {
namespace order {

Order::Order(float price, float amount, enum OrderMargin margin,
             enum OrderType type)
    : m_price(price),
      m_amount(amount),
      m_margin(margin),
      m_type(type),
      m_status(OPEN) {}

}  // namespace order
}  // namespace auto_trader