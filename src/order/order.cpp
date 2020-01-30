#include <order/order.hpp>

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace auto_trader {
namespace order {

OrderProperties::OrderProperties() {
  boost::uuids::random_generator generator;
  identifier = generator();
}

Order::Order(float price, float amount, enum OrderMargin margin,
             enum OrderType type)
    : m_properties(std::make_unique<OrderProperties>()) {
  m_properties->price = price;
  m_properties->amount = amount;
  m_properties->amount = margin;
  m_properties->type = type;
  m_properties->status = OPEN;
}

void Order::change_status(enum OrderStatus status) {
  m_properties->status = status;
}

OrderProperties* Order::get_order_details() { return m_properties.get(); }

}  // namespace order
}  // namespace auto_trader