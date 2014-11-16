#include "core/config/Config.h"
#include "core/config/XmlFileLoader.h"
#include "os/StringBuffer.h"

#include "tinyxml2/tinyxml2.h"

#define DEFINE_SECTION "config"
#define DEFINE_SUB_SECTIONS {"modules", "admin"};

namespace Core
{
	namespace Config
	{
		XmlConfigFileLoader::XmlConfigFileLoader(const OS::String& filename_)
		{
			load(filename_);
		}

		XmlConfigFileLoader::~XmlConfigFileLoader() {}

		void XmlConfigFileLoader::load(const OS::String& filename_) // throws Core::Config::ConfigException
		{
			tinyxml2::XMLError error(doc.LoadFile(filename_.c_str()));
			if (error != 0)
				throw ConfigException((OS::StringBuffer() << "file " << filename_ << " could not be oppended").c_str());

			tinyxml2::XMLNode *node = doc.FirstChild();
			if (node == NULL) 
				throw ConfigException((OS::StringBuffer() << "file " << filename_ << " is invalid (missing configurations section)").c_str());

			//tinyxml2::XMLNode *modules = node->FirstChild();

		} 
	}
}
