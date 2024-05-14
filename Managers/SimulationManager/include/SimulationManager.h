#ifndef SIMULATION_MANAGER_H
#define SIMULATION_MANAGER_H

#include "Constants.h"
#include "FastDDSPubWrapper.h"
#include "IFastDDSPubWrapper.h"
#include "FastDDSSubWrapper.h"
#include "IFastDDSSubWrapper.h"
#include "InitializeMessagePubSubTypes.h" 

namespace Manager
{
  class SimulationManager
  {
    public:
      SimulationManager();
      void initialize();
      void run();

    private:
      Common::FastDDSPubWrapper<InitializeMessagePubSubType,InitializeMessage> implInitMsgPublisher{Constants::TopicNames::initBackendTopic};
      Common::FastDDSSubWrapper<InitializeMessagePubSubType,InitializeMessage> implInitMsgSubscriber{Constants::TopicNames::initIntegrationTopic};
      Common::IFastDDSPubWrapper<InitializeMessagePubSubType,InitializeMessage>* initializeMsgPublisher;
      Common::IFastDDSSubWrapper<InitializeMessagePubSubType,InitializeMessage>* initializeMsgSubscriber;
      
  };
} // namespace Manager

#endif