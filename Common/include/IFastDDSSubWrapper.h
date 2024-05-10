#ifndef I_FAST_DDS_SUB_WRAPPER_H
#define I_FAST_DDS_SUB_WRAPPER_H

namespace Common
{
  template<typename NewPubSubType, typename NewMsgType> class IFastDDSSubWrapper
  {
    public:
      virtual NewMsgType* getMessage() = 0;
  };
} // namespace Common
#endif