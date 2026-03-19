CXX = g++
CXXFLAS = -std=c++17 -Wall

TARGET = main

OBJS = main.o board.o solveNQueens.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp board.h solveNQueens.h
	$(CXX) $(CXXFLAGS) -c main.cpp

board.o: board.cpp board.h
	$(CXX) $(CXXFLAGS) -c board.cpp

solveNQueens.o: solveNQueens.cpp solveNQueens.h board.h
	$(CXX) $(CXXFLAGS) -c solveNQueens.cpp

clean:
	rm -f $(OBJS) $(TARGET)