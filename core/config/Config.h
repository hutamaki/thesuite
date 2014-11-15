#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "os/String.h"

#include <vector>

/* 
   <config version=1>
   <modules>
   <plugin>binary_pm</plugin>
   <plugin>config_commander</plugin>
   <plugin>order_config</plugin>
   </modules>

   <INPUT name=config_commander />

   <PM type=binary />

   <shutdown time=20:00 />
   </config>
 */

/*
 * module
 */

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
