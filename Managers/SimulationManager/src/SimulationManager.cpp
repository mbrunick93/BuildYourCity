#include "SimulationManager.h"

namespace Manager
{
  SimulationManager::SimulationManager()
  {
    initializeMsgPublisher  = &implInitMsgPublisher;
    initializeMsgSubscriber = &implInitMsgSubscriber;
    tickMsgPublisher = &implTickMsgPublisher;
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

  void SimulationManager::run() {
    TickMessage newMsg;

    revenue += 1.0f;
    population  += 2;
    happiness+= 1.0f;
    if (happiness > 99.0)
    {
      happiness = 0;
    }
    newMsg.happiness(happiness);
    newMsg.population(population);
    newMsg.revenue(revenue);
    newMsg.tickValue(tickValue++);
    tickMsgPublisher->publish(newMsg);

  }
} // namespace Manager