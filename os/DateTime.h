#ifndef __DATETIME_H__
#define __DATETIME_H__

#include <time.h>
#include <iostream>

namespace OS
{
	class DateTime
	{
	public:
		DateTime(time_t tstamp_);		
		static DateTime Now();

		friend std::ostream& operator<<(std::ostream& out_, const DateTime& dateTime_);
	private:
		time_t tstamp;		
	};
}

#endif
