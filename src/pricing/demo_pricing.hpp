#ifndef _PRICING_DEMO_PRICING_
#define _PRICING_DEMO_PRICING_

#include <pricing/template.hpp>

namespace auto_trader {
namespace pricing {

class DemoPricing : PricingTemplate {
 public:
  DemoPricing() = default;
  ~DemoPricing() = default;

  float get_price() override;
};

}  // namespace pricing
}  // namespace auto_trader

#endif