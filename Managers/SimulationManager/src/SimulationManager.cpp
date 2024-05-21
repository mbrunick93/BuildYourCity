#include "SimulationManager.h"

namespace Manager
{
  SimulationManager::SimulationManager()
  {
    initializeMsgPublisher  = &implInitMsgPublisher;
    initializeMsgSubscriber = &implInitMsgSubscriber;
  }
  void SimulationManager::initialize()
  {
    bool initRecvd = false;
    do
    {
      const InitializeMessage* msg = initializeMsgSubscriber->getMessage();
      if ( msg != nullptr )
      {
        initializeMsgPublisher->publish( *msg );
        initRecvd = true;
      }
    } while ( !initRecvd );
  }

  void SimulationManager::run() {}
} // namespace Manager