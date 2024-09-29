# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Source files and executable
SRC = Scripts/main.cpp Scripts/database.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = 4MPUTester

# Path to the dependencies
LIB_PATH = ./Dependancies
LIBS = -lsqlite3 -lxlsxio_read

# Default target
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ) -L$(LIB_PATH) $(LIBS) -Wl,-rpath=$(LIB_PATH)

# Rule to compile .cpp files
Scripts/%.o: Scripts/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the generated files
clean:
	rm -rf $(OBJ) $(EXEC)

# Phony targets
.PHONY: all clean
