#ifndef __CONFIG_EXCEPTION_H__
#define __CONFIG_EXCEPTION_H__

#include "os/String.h"

#include <iostream>
#include <stdexcept>

namespace Core
{
	namespace Config
	{
		class ConfigException : public std::runtime_error
		{
			public:
				ConfigException(const OS::String& reason_) : std::runtime_error(reason_.c_str()) { }
		};
	}
}

#endif
