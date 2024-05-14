#ifndef BASE_MODULE_H
#define BASE_MODULE_H

namespace Common
{
  class BaseModule
  {
    public:
      explicit BaseModule( int id ) : id( id ){};
      struct Metrics
      {
          int population{ 0 };
          int revenue{ 0 };
          int powerUsed{ 0 };
          int powerProduced{ 0 };
          int polllionProduced{ 0 };
      };

      virtual bool initialize()       = 0;
      virtual void calculateMetrics() = 0;
      virtual ~BaseModule()           = default;

      inline Metrics getMetrics() const
      {
        return metrics;
      };
      inline int getId() const
      {
        return id;
      };

    protected:
      Metrics metrics;
      int     id;
  };
} // namespace Common

#endif