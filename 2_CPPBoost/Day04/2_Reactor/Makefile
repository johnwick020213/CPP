# Makefile for building the project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11 -O2

# Linker flags
LDFLAGS =

# Source files
SRCS = Acceptor.cc InetAddress.cc Socket.cc SocketIO.cc TcpConnection.cc EventLoop.cc Testepoll.cc

# Object files
OBJS = $(SRCS:.cc=.o)

# Executable name
TARGET = Testepoll

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

# Rule to build object files from source files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean

