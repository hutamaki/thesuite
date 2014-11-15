#ifndef __MODULELOADER_H__
#define __MODULELOADER_H__

#include "Module.h"

namespace Core
{
	class ModuleLoader
	{
	public:
		Core::Module::Module& load(const OS::String& path_);
	};
}

#endif
