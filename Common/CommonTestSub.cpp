
#include "FastDDSSubWrapper.h"
#include "TestPubSubTypes.h"

int main()
{
  std::string                                    testTopic( "TestTopic" );
  Common::FastDDSubWrapper<TestPubSubType, Test> testSubscriber( testTopic );

  Test msg;
  while ( true )
  {
    Test* gotMessage = testSubscriber.getMessage();
    if ( gotMessage != nullptr )
    {
      std::string t = gotMessage->message();
      std::cout << "Got subscriber message " << t << std::endl;
    }
  }
}