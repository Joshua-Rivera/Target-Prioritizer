CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/Bot.cpp \
      $(SRC_DIR)/Target.cpp \
      $(SRC_DIR)/Calculations.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = sim

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
