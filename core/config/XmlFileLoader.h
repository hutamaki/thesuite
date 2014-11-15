#ifndef __XMLFILELOADER_H__
#define __XMLFILELOADER_H__

#include "os/String.h"

#include "core/config/Config.h"
#include "core/config/ConfigException.h"

#include "tinyxml2/tinyxml2.h"

namespace Core
{
	namespace Config
	{
		class XmlConfigFileLoader
		{
		public:
			XmlConfigFileLoader(const OS::String& filename_);
			~XmlConfigFileLoader();

			inline const Section& getSection() const {  return *section; }
		private:
			void load(const OS::String& filename_); // throws Core::Config::ConfigException
		private:			
			Section *section;
			tinyxml2::XMLDocument doc; 
		};
	}
}

#endif
