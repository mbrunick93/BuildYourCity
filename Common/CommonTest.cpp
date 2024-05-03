#include "FastDDSPubWrapper.h"
#include "FastDDSSubWrapper.h"
#include "TestPubSubTypes.h"
#include <chrono>
#include <thread>

int main()
{
  std::string                                     testTopic( "TestTopic" );
  Common::FastDDSPubWrapper<TestPubSubType, Test> testPublisher( testTopic );
  Common::FastDDSSubWrapper<TestPubSubType, Test> testSubScriber( testTopic );

  static int count = 0;
  std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
  Test  msg;
  Test* gotMessage;
  while ( count < 10 )
  {
    Test* gotMessage{ nullptr };
    std::cout << "Sending publisher message " << std::to_string( count ) << std::endl;
    msg.message( std::to_string( count ) );
    testPublisher.publish( msg );
    std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
    gotMessage = testSubScriber.getMessage();
    if ( gotMessage != nullptr )
    {
      std::cout << "Message got = " << gotMessage->message() << "\n";
    }

    count++;
    std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
  }
}