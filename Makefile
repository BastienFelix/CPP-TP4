# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iheaders

# Target executable
TARGET = main

# Source files
SRCS = src/main.cpp src/Parcelle.cpp src/Carte.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Linking object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)