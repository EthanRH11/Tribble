#Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++17
#Source Files and object files
#Must add any new .cpp files to this list
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
#Header Files
#Not necessary to add more hpp files, but good for documentaion
HEADERS = $(wildcard *.hpp)
#Output executable
TARGET = program
#Default target: compile the program
all: program
#Rule to build the program and run valgrind
program: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)
#Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
#Rule to build the object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<
#Clean up intermediate files
clean: 
	del -f $(OBJS) $(TARGET)
