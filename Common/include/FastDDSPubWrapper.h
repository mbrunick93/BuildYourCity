#ifndef FAST_DDS_PUB_WRAPPER_H
#define FAST_DDS_PUB_WRAPPER_H

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <string>

#include "FastDDSPubListener.h"
#include "IFastDDSPubWrapper.h"

namespace Common
{
  template<typename NewPubSubType, typename NewMsgType>
  class FastDDSPubWrapper : public Common::IFastDDSPubWrapper<NewPubSubType, NewMsgType>
  {
    public:
      explicit FastDDSPubWrapper( std::string const& topicName ) : type( new NewPubSubType() )
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
        eprosima::fastdds::dds::PublisherQos pubQOS = eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT;

        // Setup publisher
        publisher = participant->create_publisher( pubQOS, nullptr );
        if ( publisher == nullptr )
        {
          std::cout << "Publisher Error";
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

        // Setup Writer
        eprosima::fastdds::dds::DataWriterQos wqos = eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT;

        writer = publisher->create_datawriter( topic, wqos, &listener );
        if ( writer == nullptr )
        {
          std::cout << "Writer Error";
          abort();
        }
      };

      virtual ~FastDDSPubWrapper()
      {
        if ( writer != nullptr )
        {
          publisher->delete_datawriter( writer );
        }
        if ( publisher != nullptr )
        {
          participant->delete_publisher( publisher );
        }
        if ( topic != nullptr )
        {
          participant->delete_topic( topic );
        }
        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(
            participant );
      }

      void publish( NewMsgType messageToPublish ) override
      {
        writer->write( &messageToPublish );
      };

    private:
      eprosima::fastdds::dds::DomainParticipant* participant{ nullptr };
      eprosima::fastdds::dds::Publisher*         publisher{ nullptr };
      eprosima::fastdds::dds::Topic*             topic{ nullptr };
      eprosima::fastdds::dds::DataWriter*        writer{ nullptr };
      eprosima::fastdds::dds::TypeSupport        type;
      eprosima::fastdds::dds::DomainId_t         domainId{ 0 };
      FastDDSPubListener                         listener;
  };
} // namespace Common

#endif