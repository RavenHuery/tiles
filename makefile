CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++11

game.o: game.cpp



#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = game.cc board.cc moveTile.cc tileType.cc

# Object files
OBJS = $(SRCS:.cc=.o)

# Header files
HDRS = game.h board.h moveTile.h tileType.h

# Executable name
TARGET = game

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
#%.o: %.cc $(HDRS)
$(OBJS): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean the generated files
clean:
	rm -f $(OBJS) $(TARGET)
