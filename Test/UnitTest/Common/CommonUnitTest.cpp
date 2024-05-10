#include "CommonMessagePubSubTypes.h"
#include "FastDDSMocks.h"
#include "FastDDSPubWrapper.h"
#include "IFastDDSPubWrapper.h"

#include <gtest/gtest.h>

using ::testing::AtLeast;
using ::testing::Return;

TEST( CommonUnitTest, PublisherTest )
{
  std::string testTopicName( "TestTopicName" );

  Common::IFastDDSPubWrapper<CommonMessagePubSubType, CommonMessage>* publisher{ nullptr };
  TestMocks::PublisherMock<CommonMessagePubSubType, CommonMessage>    pubMock;

  CommonMessage testMessage;
  testMessage.publisher( PubSubTypeEnum::GUI );
  testMessage.subscriber( PubSubTypeEnum::SIMULATION_MANAGER );

  publisher = &pubMock;

  EXPECT_CALL( pubMock, publish( testMessage ) ).Times( AtLeast( 1 ) );
  publisher->publish( testMessage );
}

TEST( CommonUnitTest, SubscriberTest )
{
  std::string testTopicName( "TestTopicName" );

  Common::IFastDDSSubWrapper<CommonMessagePubSubType, CommonMessage>* subscriber{ nullptr };
  TestMocks::SubscriberMock<CommonMessagePubSubType, CommonMessage>   subMock;

  subscriber = &subMock;
  CommonMessage testMessage;
  testMessage.publisher( PubSubTypeEnum::GUI );
  testMessage.subscriber( PubSubTypeEnum::SIMULATION_MANAGER );

  EXPECT_CALL( subMock, getMessage() )
      .WillOnce( Return( nullptr ) )
      .WillOnce( Return( &testMessage ) );
  CommonMessage* recvMessage = subscriber->getMessage();
  EXPECT_EQ( recvMessage, nullptr );
  recvMessage = subscriber->getMessage();
  EXPECT_EQ( recvMessage->publisher(), PubSubTypeEnum::GUI );
  EXPECT_EQ( recvMessage->subscriber(), PubSubTypeEnum::SIMULATION_MANAGER );
}