#ifndef __MODULE_H__
#define __MODULE_H__

#include "os/String.h"
#include "modulesIds.h"

namespace Core
{
	namespace Module
	{
		class Module
		{
		public:
			Module(const OS::String& path_) : path(path_) {}
			virtual Module::Id& getID() const = 0;
		private:
			OS::String path;
		};
	}
}

#endif

