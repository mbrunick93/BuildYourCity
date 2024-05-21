#ifndef SIMULATION_MANAGER_H
#define SIMULATION_MANAGER_H

#include "Constants.h"
#include "FastDDSPubWrapper.h"
#include "FastDDSSubWrapper.h"
#include "IFastDDSPubWrapper.h"
#include "IFastDDSSubWrapper.h"
#include "InitializeMessagePubSubTypes.h"
#include "TickMessagePubSubTypes.h"

namespace Manager
{
  class SimulationManager
  {
    public:
      SimulationManager();
      void initialize();
      void run();

    private:
      Common::FastDDSPubWrapper<InitializeMessagePubSubType, InitializeMessage>
          implInitMsgPublisher{ Constants::TopicNames::initBackendTopic };
      Common::FastDDSSubWrapper<InitializeMessagePubSubType, InitializeMessage>
          implInitMsgSubscriber{ Constants::TopicNames::initIntegrationTopic };
      Common::IFastDDSPubWrapper<InitializeMessagePubSubType, InitializeMessage>*
          initializeMsgPublisher;
      Common::IFastDDSSubWrapper<InitializeMessagePubSubType, InitializeMessage>*
          initializeMsgSubscriber;
      Common::FastDDSPubWrapper<TickMessagePubSubType,TickMessage> implTickMsgPublisher{Constants::TopicNames::tickTopic};
      Common::IFastDDSPubWrapper<TickMessagePubSubType,TickMessage>* tickMsgPublisher;

      int tickValue{0};
      int population{0};
      float happiness{0.0};
      float revenue{0.0};

  };
} // namespace Manager

#endif