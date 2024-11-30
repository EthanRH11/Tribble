# Compiler and Flags
CXX = g++ 
CXXFLAGS = -Wall -g -std=c++17

# Source Files and Object Files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Header Files
HEADERS = $(wildcard *.hpp)

# Output executable
TARGET = program

# Default target: compile the program
all: program

# Rule to build the program and run valgrind
program: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	valgrind --leak-check=full ./$(TARGET)

# Target to compile and run program with Tribble.txt as input and output to output.txt
interperter: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)  # Compile the main.cpp and other sources
	./$(TARGET) Tribble.txt output.txt          # Run the program and redirect output

# Clean up intermediate files
clean:
	rm -f $(OBJS) $(TARGET)
