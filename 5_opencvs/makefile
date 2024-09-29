# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := `pkg-config --cflags opencv4`

# Linker flags
LDFLAGS := `pkg-config --libs opencv4`

# Target executable
TARGET := a

# Source files
SRCS := main.cpp

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET)
