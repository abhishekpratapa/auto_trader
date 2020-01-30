#ifndef _ORDER_ORDER_
#define _ORDER_ORDER_

#include <memory>
#include <string>

#include <boost/uuid/uuid.hpp>

namespace auto_trader {
namespace order {

enum OrderMargin {
  ONE,
  TWO,
  FIVE,
  TEN,
  TWENTY_FIVE,
  FIFTY,
  ONE_HUNDRED,
};

enum OrderType {
  SHORT,
  LONG,
};

enum OrderStatus {
  OPEN,
  ACTIVE,
  CLOSED,
  CANCELED,
  LIQUIDATED,
};

struct OrderProperties {
  boost::uuids::uuid identifier;

  float price;
  float amount;
  enum OrderMargin margin;
  enum OrderType type;
  enum OrderStatus status;

  OrderProperties();
  ~OrderProperties() = default;
};

class Order {
 public:
  Order() = delete;
  Order(float price, float amount, enum OrderMargin margin,
        enum OrderType type);
  Order(std::unique_ptr<OrderProperties> properties)
      : m_properties(std::move(properties)){};
  ~Order() = default;

  void change_status(enum OrderStatus status);
  OrderProperties* get_order_details();

 private:
  std::unique_ptr<OrderProperties> m_properties;
};

}  // namespace order
}  // namespace auto_trader

#endif