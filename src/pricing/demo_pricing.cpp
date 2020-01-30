#include <pricing/demo_pricing.hpp>

#include <math.h>

namespace auto_trader {
namespace pricing {

namespace {

float degrees_to_radians(float degrees) { return ((degrees * M_PI) / 180.0); }

}  // namespace

float DemoPricing::get_price() {
  return 500.0 * (sin(degrees_to_radians(m_step)) + 1);
}

}  // namespace pricing
}  // namespace auto_trader