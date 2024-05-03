#ifndef FAST_DDS_PUB_LISTENER_H
#define FAST_DDS_PUB_LISTENER_H

#include <fastdds/dds/publisher/DataWriterListener.hpp>

namespace Common
{
  class FastDDSPubListener : public eprosima::fastdds::dds::DataWriterListener
  {
    public:
      FastDDSPubListener() : matched_( 0 ), firstConnected_( false ) {}

      ~FastDDSPubListener() override {}

      void on_publication_matched(
          eprosima::fastdds::dds::DataWriter*                     writer,
          const eprosima::fastdds::dds::PublicationMatchedStatus& info ) override;

      int matched_;

      bool firstConnected_;
  };

} // namespace Common

#endif