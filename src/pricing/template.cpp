#include <pricing/template.hpp>

namespace auto_trader {
namespace pricing {

float PricingTemplate::next() {
  m_step++;
  return this->get_price();
}

float PricingTemplate::previous() {
  m_step--;
  return this->get_price();
}

float PricingTemplate::current() { return this->get_price(); }

}  // namespace pricing
}  // namespace auto_trader