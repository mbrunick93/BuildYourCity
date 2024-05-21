#ifndef GODOT_DDS_WRAPPER_H
#define GODOT_DDS_WRAPPER_H

#include "FastDDSSubWrapper.h"
#include "IFastDDSSubWrapper.h"
#include "TickMessagePubSubTypes.h"
#include <godot_cpp/classes/control.hpp>
#include <string>

namespace godot
{
  class GodotDDSWrapper : public Node
  {
      GDCLASS( GodotDDSWrapper, Node )
    public:
      GodotDDSWrapper();

      void   update();
      String getPopulation();
      String getRevenue();
      String getTick();
      float getHappiness();

    protected:
      static void _bind_methods();

    private:
      Common::IFastDDSSubWrapper<TickMessagePubSubType, TickMessage>* tickSubscriber{ nullptr };
      Common::FastDDSSubWrapper<TickMessagePubSubType, TickMessage>   implTickSubscriber;
      std::string                                                     currentTick{ "0" };
      std::string                                                     population{ "0" };
      std::string                                                     revenue{ "0" };
      float                                                            happiness{ 0.0 };
  };
} // namespace godot
#endif