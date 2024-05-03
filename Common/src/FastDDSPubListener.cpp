#include "FastDDSPubListener.h"

namespace Common
{

  void FastDDSPubListener::on_publication_matched(
      eprosima::fastdds::dds::DataWriter*                     writer,
      const eprosima::fastdds::dds::PublicationMatchedStatus& info )
  {
    if ( info.current_count_change == 1 )
    {
      matched_        = info.total_count;
      firstConnected_ = true;
      std::cout << "Publisher matched." << std::endl;
    }
    else if ( info.current_count_change == -1 )
    {
      matched_ = info.total_count;
      std::cout << "Publisher unmatched." << std::endl;
    }
    else
    {
      std::cout << info.current_count_change
                << " is not a valid value for PublicationMatchedStatus current count change"
                << std::endl;
    }
  }
} // namespace Common