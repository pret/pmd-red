CXX ?= g++

CXXFLAGS := -Wall -std=c++11 -O2

SRCS := json11.cpp dungeonjson.cpp

HEADERS := dungeonjson.h

.PHONY: all clean

all: dungeonjson
	@:

dungeonjson: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) dungeonjson dungeonjson.exe
