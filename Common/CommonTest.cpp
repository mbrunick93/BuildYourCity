#include "FastDDSPubWrapper.h"
#include "TestPubSubTypes.h"

int main()
{
  std::string                                     testTopic( "TestTopic" );
  Common::FastDDSPubWrapper<TestPubSubType, Test> testPublisher( testTopic );

  static int count = 0;

  Test msg;
  while ( count < 10 )
  {
    std::cout << "Sending publisher message " << std::to_string( count ) << std::endl;
    msg.message( std::to_string( count ) );
    testPublisher.publish( msg );

    count++;
  }
}