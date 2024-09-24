# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Source files and executable
SRC = Scripts/main.cpp Scripts/database.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = 4MPUTester

# Default target
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Rule to compile .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the generated files
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets
.PHONY: all clean
