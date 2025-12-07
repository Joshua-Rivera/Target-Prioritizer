CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = main.cpp Bot.cpp Target.cpp Calculations.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = sim

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
