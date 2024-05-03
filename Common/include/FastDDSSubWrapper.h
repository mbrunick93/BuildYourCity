#ifndef FAST_DDS_SUB_WRAPPER_H
#define FAST_DDS_SUB_WRAPPER_H

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>

#include "FastDDSSubListener.h"

namespace Common
{
  template<typename NewPubSubType, typename NewMsgType> class FastDDSSubWrapper
  {
    public:
      explicit FastDDSSubWrapper( std::string const& topicName ) : type( new NewPubSubType() )
      {
        eprosima::fastdds::dds::DomainParticipantQos partQOS =
            eprosima::fastdds::dds::PARTICIPANT_QOS_DEFAULT;
        auto factory = eprosima::fastdds::dds::DomainParticipantFactory::get_instance();

        // Setup participant
        participant = factory->create_participant( domainId, partQOS );
        if ( participant == nullptr )
        {
          std::cout << "Factory error";
          abort();
        }

        type.register_type( participant );
        eprosima::fastdds::dds::SubscriberQos subQOS =
            eprosima::fastdds::dds::SUBSCRIBER_QOS_DEFAULT;

        // Setup publisher
        subscriber = participant->create_subscriber( subQOS, nullptr );
        if ( subscriber == nullptr )
        {
          std::cout << "Subscriber Error";
          abort();
        }

        // Setup topic
        eprosima::fastdds::dds::TopicQos tqos = eprosima::fastdds::dds::TOPIC_QOS_DEFAULT;
        topic = participant->create_topic( topicName, type.get_type_name(), tqos );
        if ( topic == nullptr )
        {
          std::cout << "Topic Error";
          abort();
        }

        // Setup Reader
        eprosima::fastdds::dds::DataReaderQos rqos = eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT;
        reader = subscriber->create_datareader( topic, rqos, &listener );
        if ( reader == nullptr )
        {
          std::cout << "Reader Error";
          abort();
        }

      };

      ~FastDDSSubWrapper()
      {
        if ( reader != nullptr )
        {
          subscriber->delete_datareader( reader );
        }
        if ( topic != nullptr )
        {
          participant->delete_topic( topic );
        }
        if ( subscriber != nullptr )
        {
          participant->delete_subscriber( subscriber );
        }
        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(
            participant );
      }

      NewMsgType* getMessage()
      {
        if ( reader->take_next_sample( &message, &sampleinfo ) == ReturnCode_t::RETCODE_OK )
        {
            return &message;
        }
        else
        {
          return nullptr;
        }
      }

    private:
      eprosima::fastdds::dds::DomainParticipant* participant{ nullptr };
      eprosima::fastdds::dds::Subscriber*        subscriber{ nullptr };
      eprosima::fastdds::dds::Topic*             topic{ nullptr };
      eprosima::fastdds::dds::DataReader*        reader{ nullptr };
      eprosima::fastdds::dds::TypeSupport        type;
      eprosima::fastdds::dds::DomainId_t         domainId{ 0 };
      eprosima::fastdds::dds::SampleInfo         sampleinfo;
      FastDDSSubListener                         listener;
      NewMsgType                                 message;
  };
} // namespace Common
#endif