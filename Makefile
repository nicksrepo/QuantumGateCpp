# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Build target executable
TARGET = quantum_vm_sim

# Source files
SRC = main.cpp VirtualQubit.cpp QuantumVM.cpp QuantumGate.cpp QuantumRandomNumberGenerator.cpp QRegister.cpp


# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# To obtain object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# To remove generated files
clean:
	rm -f $(TARGET) $(OBJ)
