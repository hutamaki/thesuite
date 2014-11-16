CXX = g++

CPPFLAGS = -g -Wall -pedantic -DLINUX 
LDFLAGS = 
LDLIBS = -lpthread

INCLUDES = -I. -Ithirdparties

SRCS    = $(shell find $(SRCDIR) -name '*.cpp')
SRCDIRS = $(shell find . -name '*.cpp' -exec dirname {} \; | uniq)
OBJS		= $(subst .cpp,.o,$(SRCS))

TARGET = thesuite

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(INCLUDES) $(CPPFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

cleanall: clean
	rm -fr $(TARGET)
