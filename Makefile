.PHONY: all clean rebuild

TARGET = sort_benchmark

CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall

HEADERS = sorts_simple.h MeasTime.h
SOURCES = main.cpp sorts_simple.cpp MeasTime.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all
