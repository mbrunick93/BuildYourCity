#include "SingleFamilyHome.h"

namespace Residential
{

  SingleFamilyHome::SingleFamilyHome( int id ) : BaseModule( id ) {}
  bool SingleFamilyHome::initialize()
  {
    metrics.population = 1;
  }

  void SingleFamilyHome::calculateMetrics() {}

} // namespace Residential