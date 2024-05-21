#include "GodotDDSWrapper.h"
#include <godot_cpp/core/class_db.hpp>

#include "Constants.h"
namespace godot
{
  void GodotDDSWrapper::_bind_methods()
  {
    ClassDB::bind_method( D_METHOD( "update" ), &GodotDDSWrapper::update );
    ClassDB::bind_method( D_METHOD( "getPopulation" ), &GodotDDSWrapper::getPopulation );
    ClassDB::bind_method( D_METHOD( "getRevenue" ), &GodotDDSWrapper::getRevenue );
    ClassDB::bind_method( D_METHOD( "getTick" ), &GodotDDSWrapper::getTick );
    ClassDB::bind_method( D_METHOD( "getHappiness" ), &GodotDDSWrapper::getHappiness );
  }

  GodotDDSWrapper::GodotDDSWrapper() :
      implTickSubscriber( Constants::TopicNames::tickTopic ), tickSubscriber( &implTickSubscriber )
  {
  }

  void GodotDDSWrapper::update()
  {
    TickMessage* newMsg = tickSubscriber->getMessage();
    if ( newMsg != nullptr )
    {
      currentTick = std::to_string( newMsg->tickValue() );
      revenue     = std::to_string( newMsg->revenue() );
      population  = std::to_string( newMsg->population() );
      
    }
  }
  String GodotDDSWrapper::getPopulation()
  {
    return population.c_str();
  }
  String GodotDDSWrapper::getRevenue()
  {
    return revenue.c_str();
  }
  String GodotDDSWrapper::getTick()
  {
    return currentTick.c_str();
  }

  float GodotDDSWrapper::getHappiness()
  {
    return happiness;
  }

} // namespace godot