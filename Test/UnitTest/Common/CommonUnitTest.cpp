#include "FastDDSPubWrapper.h"
#include "IFastDDSPubWrapper.h"
#include "CommonMessagePubSubTypes.h"

#include <gtest/gtest.h>

TEST( CommonUnitTest, TestOne )
{
  std::string testTopicName("TestTopicName");
  Common::IFastDDSPubWrapper<CommonMessagePubSubType,CommonMessage>* publisher{nullptr};
  Common::FastDDSPubWrapper<CommonMessagePubSubType,CommonMessage> implPublisher(testTopicName);
  publisher = &implPublisher;

  EXPECT_NE(publisher,nullptr);
}