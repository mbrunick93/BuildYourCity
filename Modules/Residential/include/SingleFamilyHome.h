#ifndef SINGLE_FAMILY_HOME
#define SINGLE_FAMILY_HOME

#include "BaseModule.h"
namespace Residential
{
  class SingleFamilyHome : public Common::BaseModule
  {
    public:
      explicit SingleFamilyHome( int id );
      bool initialize() override;
      void calculateMetrics() override;

    private:
  };
} // namespace Residential
#endif