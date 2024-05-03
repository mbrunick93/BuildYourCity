#include "FastDDSPubWrapper.h"
#include "TestPubSubTypes.h"
#include "TestTwoPubSubTypes.h"

int main()
{
  TestPubSubType                                  test;
  Test                                            msg;
  std::string                                     testTopic( "TestTopic" );
  Common::FastDDSPubWrapper<TestPubSubType, Test> testPublisher( testTopic );

  msg.message( "hello" );

  testPublisher.publish( msg );
}