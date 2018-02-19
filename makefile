CC = g++
CC_FLAGS = -std=c++11 -Wall -Werror -pedantic

EXECUTABLE = rshell
SOURCEDIR = src
BUILDER = bin

OBJECTS = test.o shell.o Base.o
SOURCES = src/test.cpp src/shell.cpp src/Base.cpp


all: $(SOURCES)
	mkdir -p $(BUILDER)
	$(CC) $(CC_FLAGS) $(SOURCES) -o $(BUILDER)/$(EXECUTABLE)


rshell: $(SOURCES)
	mkdir -p $(BUILDER)
	$(CC) $(CC_FLAGS) $(SOURCES) -o $(BUILDER)/$(EXECUTABLE)

clean: $(SOURCES)
	rm -f $(EXECUTABLE) $(OBJECTS)
	rm -rf $(BUILDER)
	