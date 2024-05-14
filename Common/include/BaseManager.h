#ifndef BASE_MANAGER_H
#define BASE_MANAGER_H

#include <map>
namespace Common
{
  template<typename ModuleType> class BaseManager
  {
    public:
      virtual void initialize()     = 0;
      virtual void sendMessage()    = 0;
      virtual void receiveMessage() = 0;
      virtual void run()            = 0;
      inline bool  addModule( const int id )
      {
        bool returnValue = false;
        if ( moduleMap.find( id ) == moduleMap.end() )
        {
          ModuleType newModule( id );
          moduleMap[id] = newModule;
          returnValue   = true;
        }
        return returnValue;
      };

      inline void removeModule( const int id )
      {
        moduleMap.erase( id );
      };

      virtual ~BaseManager() = default;

    private:
      std::map<int, ModuleType> moduleMap;
  };

} // namespace Common
#endif