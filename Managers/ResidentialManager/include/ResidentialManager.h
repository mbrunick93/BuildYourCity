#ifndef RESIDENTIAL_MANAGER_H
#define RESIDENTIAL_MANAGER_H

#include "BaseManager.h"

namespace Manager
{
  template<typename ModuleType> class ResidentialManager : public Common::BaseManager<ModuleType>
  {
    public:
      void initialize() override;
      void sendMessage() override;
      void receiveMessage() override;
      void run() override;
      virtual ~ResidentialManager() = default;

    private:
  };
} // namespace Manager

#endif