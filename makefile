CC = g++
CC_FLAGS = -std=c++11 -Wall -Werror -pedantic

EXECUTABLE = rshell
SOURCEDIR = src
BUILDER = bin

OBJECTS = test.cpp Base.cpp shell.cpp


all: $(OBJECTS)
	mkdir -p $(BUILDER)
	$(CC) $(CC_FLAGS) $(OBJECTS) -o $(BUILDER)/$(EXECUTABLE)


rshell: $(OBJECTS)
	mkdir -p $(BUILDER)
	$(CC) $(CC_FLAGS) $(OBJECTS) -o $(BUILDER)/$(EXECUTABLE)

clean: $(OBJECTS)
	rm -f $(EXECUTABLE) $(OBJECTS)
	rm -rf $(BUILDER)

