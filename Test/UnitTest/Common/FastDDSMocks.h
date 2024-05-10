#ifndef FAST_DDS_MOCKS_H
#define FAST_DDS_MOCKS_H

#include "IFastDDSPubWrapper.h"
#include "IFastDDSSubWrapper.h"
#include <gmock/gmock.h>

namespace TestMocks
{
  template<typename NewPubSubType, typename NewMsgType>
  class PublisherMock : public Common::IFastDDSPubWrapper<NewPubSubType, NewMsgType>
  {
    public:
      MOCK_METHOD( void, publish, (NewMsgType messageToPublish), ( override ) );
  };

  template<typename NewPubSubType, typename NewMsgType>
  class SubscriberMock : public Common::IFastDDSSubWrapper<NewPubSubType, NewMsgType>
  {
    public:
      MOCK_METHOD( NewMsgType* , getMessage, (), ( override ) );
  };

} // namespace TestMocks

#endif