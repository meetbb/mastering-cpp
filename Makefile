# Compiler
CXX = clang++
CXXFLAGS = -std=c++17 -g -Wall -I . -I ./DSAJourney -I ./DSAJourney/TwoPointers -I ./DesignPatterns -I ./DesignPatterns/Creational -I ./DesignPatterns/Creational/Factory

# Find all .cpp files recursively
SOURCES = $(shell find . -name "*.cpp")

# Output executable
TARGET = main

# Default rule
all: $(TARGET)

# Link and build executable
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET)

# Run program
run: all
	./$(TARGET)
