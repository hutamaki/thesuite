#ifndef __STRINGBUFFER_H__
#define __STRINGBUFFER_H__

#include "os/String.h"
#include <vector>
#include <stdlib.h>

namespace OS
{
  class StringBuffer
  {
    public:
      explicit StringBuffer() : strTotalLength(0), result(NULL) {}
      StringBuffer(const OS::String& str_) : strTotalLength(str_.length()), result(NULL)
    { 
      strings.push_back(&str_); 
    }

      ~StringBuffer()
      {
        reset(); 
      }

      StringBuffer& operator<<(const OS::String& str_)
      {
        reset(); // content modification : cumulated os string needs to be resetted

        strings.push_back(&str_);
        strTotalLength += str_.length();
        return (*this);
      }

      StringBuffer& operator<<(StringBuffer& str_)
      {
        reset(); // content modification : cumulated os string needs to be resetted

        unsigned int input_size(str_.strings.size()), here_size(strings.size());
        if (strings.capacity() < (input_size + here_size))
          strings.reserve(input_size + here_size); // could be improved in case of cascadinng << for a greater size
        memcpy(strings.data() + sizeof(const OS::String *) * strings.size(), str_.strings.data(), str_.strings.size());
        strTotalLength += str_.strTotalLength;
        return (*this);
      }

      typedef std::vector<const OS::String *>::const_iterator IteratorOfStrings;

      OS::String& c_str()
      {
        result = new OS::String(strTotalLength);
        IteratorOfStrings iterator_end(strings.end());

        char *dst(result->str);
        for(IteratorOfStrings iterator(strings.begin()); iterator < iterator_end; iterator++)
        {
          const OS::String* str(*iterator);
          unsigned int lengthToCopy(strlen(str->c_str()));
          strncpy(dst, str->str, lengthToCopy);
          dst += lengthToCopy;
        }
        return *result;
      }

    private:
      void reset() { delete result; result = NULL; }

    private:
      std::vector<const OS::String *> strings;
      unsigned int strTotalLength;

      OS::String* result;		
  };
}

#endif
