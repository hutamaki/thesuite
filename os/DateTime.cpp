#include "DateTime.h"

#include <iostream>
#include <time.h>

namespace OS
{
	DateTime::DateTime(time_t tstamp_)
	{
		tstamp = tstamp_; 
	}

	DateTime DateTime::Now()
	{
		return DateTime(time(NULL));
	}

	std::ostream& operator<<(std::ostream& out_, const DateTime& dateTime_)
	{	
		char output[26];
		ctime_r(&dateTime_.tstamp, output);
		output[24] = '\0'; // index of annoying '\n'
		return (out_ << output);
	}
}


