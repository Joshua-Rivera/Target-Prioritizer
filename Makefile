CXX = g++
CXXFLAGS = -Wall -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system

SRC = src/main.cpp \
      src/Bot.cpp \
      src/Target.cpp \
      src/Calculations.cpp \
      src/Simulation.cpp \
      src/Renderer.cpp

OBJ = $(SRC:.cpp=.o)
TARGET = sim

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LDFLAGS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
