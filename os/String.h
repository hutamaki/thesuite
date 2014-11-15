#ifndef __STRING_H__
#define __STRING_H__

#include <string>

namespace OS
{
	class String
	{	
		public:			
			String(const char* str_);
			String(const String& str_);
			String(const std::string& str_);			
			~String();

			String& operator=(const char *str_);
			String& operator=(const std::string& str_);
			String& operator=(const String& str_);

			size_t length() const;
			bool empty() const;		
			const char* c_str() const;

			String& concat(const char *str_);
			String& concat(const std::string& str_);
			String& concat(const String& str_);

			String& operator+(const char *str_);
			String& operator+(const std::string& str_);
			String& operator+(const String& str_);

			friend std::ostream& operator<<(std::ostream& out, const OS::String& str_);
	private:
		String() {};		
		String(unsigned int n_);

		friend class StringBuffer;
	private:
		char *str;		
	};
}

#endif
