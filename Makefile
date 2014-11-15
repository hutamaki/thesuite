CXX = g++

CPPFLAGS = -g -Wall -pedantic -DLINUX 
LDFLAGS = 

INCLUDES = -I. -Ithirdparties

SRCS    := $(shell find $(SRCDIR) -name '*.cpp')
SRCDIRS := $(shell find . -name '*.cpp' -exec dirname {} \; | uniq)
OBJS=$(subst .cpp,.o,$(SRCS))

 #SRCS=$(wildcard **/*.cpp) $(wildcard *.cpp) $(wildcard **/*/*.cpp)
#OBJS=$(subst .cpp,.o,$(SRCS))

all: thesuite

thesuite: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(INCLUDES) $(CPPFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)
