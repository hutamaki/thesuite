#include "String.h"

#include <string.h>
#include <stdlib.h>
#include <iostream>

namespace OS
{
  String::String(const char *str_) 
  {
    str = strdup(str_);
  }

  String::String(const std::string& str_)
  {
    str = strdup(str_.c_str());
  }

  String::String(const String& str_)
  {
    str = strdup(str_.str);
  }

  String::String(unsigned int n_) : str((char *)calloc(n_ + 1, sizeof (char))) // don't forget \0 at the end
  {		
  }

  String::~String()
  {
    if (str != NULL)
      free(str);
  }

  String& String::operator=(const char *str_)
  {
    free(str);
    str = strdup(str_);
    return *this;
  }

  String& String::operator=(const std::string& str_)
  {
    (*this) = str_.c_str();
    return (*this);
  }

  String& String::operator=(const String& str_)
  {
    (*this) = str_.str;
    return (*this);
  }

  size_t String::length() const
  {
    return strlen(str);
  }

  bool String::empty() const
  {
    return (*str == '\0');
  }

  const char *String::c_str() const
  {
    return str;
  }

  String& String::concat(const char *str_)
  {
    size_t str_len = strlen(str_);
    size_t strlen = length();

    char *dest = (char *)calloc(str_len + strlen + 1, sizeof (char));
    strcpy(dest, str);
    strcpy(dest + strlen, str_);

    free(str);
    str = dest;

    return (*this);
  }

  String& String::concat(const std::string& str_)
  {
    return concat(str_.c_str());
  }

  String& String::concat(const String& str_)
  {
    return concat(str_.str);
  }

  String& String::operator+(const char *str_)
  {
    return concat(str_);
  }

  String& String::operator+(const std::string& str_)
  {
    return concat(str_.c_str());
  }

  String& String::operator+(const String& str_)
  {
    return concat(str_.str);
  }

  std::ostream& operator<<(std::ostream& out, const OS::String& str_)
  {
    return (out << str_.str);
  }
}

