#ifndef _ORDER_ORDER_
#define _ORDER_ORDER_

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

class Order {
 public:
  Order() = delete;
  Order(float price, float amount, enum OrderMargin margin,
        enum OrderType type);
  ~Order() = default;

 private:
  float m_price;
  float m_amount;
  enum OrderMargin m_margin;
  enum OrderType m_type;
  enum OrderStatus m_status;
};

}  // namespace order
}  // namespace auto_trader

#endif