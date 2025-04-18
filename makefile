# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -I./include

# Directory
SRC_DIR     = src
INCLUDE_DIR = include
BUILD_DIR   = build

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/functions.cpp

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Executable name
TARGET = main

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Cria diretório de build, se não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean rule

clean:
	rm -rf $(BUILD_DIR) $(TARGET) 

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)
