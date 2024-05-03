#ifndef FAST_DDS_PUB_WRAPPER_H
#define FAST_DDS_PUB_WRAPPER_H
#include "Constants.h"
#include <chrono>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <string>
#include <thread>

using namespace eprosima::fastdds::dds;

namespace Common
{
  class FastDDSPubWrapper
  {
  };
} // namespace Common

#endif