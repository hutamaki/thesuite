#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "os/String.h"

#include <vector>

namespace Core
{
  namespace Config
  {
    class Section
    {
      public:
        Section(const OS::String& name_) : name(name_)
      {}

      private:
        OS::String name;
        std::vector<Section> sections;
    };
  }
}


class ConfigListener
{
  public:
    virtual const OS::String& getTag() const;	
    virtual void notify(Core::Config::Section& section);
};

class ConfigCommander : public ConfigListener
{

};

#endif
