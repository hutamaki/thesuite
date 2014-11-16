#include "os/String.h"
#include "os/DateTime.h"
#include "os/Mutex.h"

#include "core/config/Config.h"
#include "core/config/XmlFileLoader.h"
#include "core/config/ConfigException.h"

#include <iostream>

int main(int argc, char **argv)
{
	OS::String lolstr("lol");
	OS::String lolstr2(lolstr);
	OS::String interstellar("insterstellar");
	OS::String lolstr3 = lolstr + lolstr2 + interstellar; 

  std::cout << lolstr << std::endl;
  std::cout << lolstr2 << std::endl;
	std::cout << lolstr3 << std::endl;

	// output utcDateTime
	OS::DateTime datetime(OS::DateTime::Now());
	std::cout << OS::DateTime::Now() << std::endl;
	std::cout << datetime << std::endl;

	// interpretation of argc, argv
	try
	{
    OS::ScopedMutex mutex;
		Core::Config::XmlConfigFileLoader config("config.xml");
	}
	catch (Core::Config::ConfigException exp)
	{
		std::cerr << exp.what() << std::endl;
	}

	return 0;
}
