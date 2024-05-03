#include "FastDDSSubListener.h"

namespace Common
{
  void FastDDSSubListener::on_subscription_matched(
      eprosima::fastdds::dds::DataReader*                      reader,
      const eprosima::fastdds::dds::SubscriptionMatchedStatus& info )
  {
    if ( info.current_count_change == 1 )
    {
      matched = info.total_count;
      std::cout << "Subscriber matched." << std::endl;
    }
    else if ( info.current_count_change == -1 )
    {
      matched = info.total_count;
      std::cout << "Subscriber unmatched." << std::endl;
    }
    else
    {
      std::cout << info.current_count_change
                << " is not a valid value for SubscriptionMatchedStatus current count change"
                << std::endl;
    }
  }

} // namespace Common