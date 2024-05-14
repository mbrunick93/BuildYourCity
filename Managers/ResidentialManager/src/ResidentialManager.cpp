#include "ResidentialManager.h"
#include "SingleFamilyHome.h"

namespace Manager
{
  template<typename ModuleType> void ResidentialManager<ModuleType>::initialize() {}
  template<typename ModuleType> void ResidentialManager<ModuleType>::sendMessage() {}
  template<typename ModuleType> void ResidentialManager<ModuleType>::receiveMessage() {}
  template<typename ModuleType> void ResidentialManager<ModuleType>::run() {}

  template class ResidentialManager<Residential::SingleFamilyHome>;
} // namespace Manager