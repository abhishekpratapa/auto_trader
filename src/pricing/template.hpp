#ifndef _PRICING_TEMPLATE_
#define _PRICING_TEMPLATE_

#include <stdlib.h>
#include <data/template.hpp>

namespace auto_trader {
namespace pricing {

class PricingTemplate {
 public:
  PricingTemplate() : m_step(0){};
  virtual ~PricingTemplate() = default;

  float next();
  float previous();
  float current();

  // TODO: plumb through DataTemplate instead of float
  virtual float get_price() = 0;

 protected:
  size_t m_step;
};

}  // namespace pricing
}  // namespace auto_trader

#endif