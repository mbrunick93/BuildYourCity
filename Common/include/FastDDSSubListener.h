#ifndef FAST_DDS_SUB_LISTENER_H
#define FAST_DDS_SUB_LISTENER_H

#include <fastdds/dds/subscriber/DataReaderListener.hpp>

namespace Common
{
  class FastDDSSubListener : public eprosima::fastdds::dds::DataReaderListener
  {
    public:
      FastDDSSubListener() = default;

      ~FastDDSSubListener() override = default;

      void on_subscription_matched(
          eprosima::fastdds::dds::DataReader*                      reader,
          const eprosima::fastdds::dds::SubscriptionMatchedStatus& info ) override;

      int matched{ 0 };
  };
} // namespace Common
#endif
