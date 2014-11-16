CXX = g++

CPPFLAGS = -g -Wall -pedantic -DLINUX 
LDFLAGS = 

INCLUDES = -I. -Ithirdparties

SRCS    = $(shell find $(SRCDIR) -name '*.cpp')
SRCDIRS = $(shell find . -name '*.cpp' -exec dirname {} \; | uniq)
OBJS		= $(subst .cpp,.o,$(SRCS))

TARGET = thesuite

all: $(TARGET)

thesuite: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(INCLUDES) $(CPPFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

cleanall: clean
	rm -fr $(TARGET)
