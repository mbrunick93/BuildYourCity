#ifndef I_FAST_DDS_PUB_WRAPPER_H
#define I_FAST_DDS_PUB_WRAPPER_H

namespace Common
{
  template<typename NewPubSubType, typename NewMsgType> class IFastDDSPubWrapper
  {
    public:
      virtual void publish( NewMsgType messageToPublish ) = 0;
  };
} // namespace Common
#endif