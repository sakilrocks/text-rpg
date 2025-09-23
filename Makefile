
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I include
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = rpg-game

all: $(TARGET)

$(TARGET): $(OBJ) main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) main.o $(TARGET)

run: all
	./$(TARGET)