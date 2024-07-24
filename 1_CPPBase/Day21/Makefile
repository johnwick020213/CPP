Srcs := $(wildcard *.c *.cc *.cpp)
Objs := $(patsubst %.c, %.o, $(patsubst %.cc, %.o, $(patsubst %.cpp, %.o, $(Srcs))))
Outs := $(patsubst %.o, %, $(Objs))

CC := gcc
CXX := g++
CFLAGS = -Wall -g
CXXFLAGS = -Wall -g

ALL: $(Outs) clean_objs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%: %.o
	$(CXX) $< -o $@

.PHONY: clean rebuild ALL clean_objs

clean:
	$(RM) $(Outs) $(Objs)

rebuild: clean ALL

clean_objs:
	$(RM) $(Objs)

