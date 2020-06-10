CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp function.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=laba2

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
