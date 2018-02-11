CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic
OBJECTS = test.cpp shell.cpp Base.cpp

all: $(OBJECTS)
	$(CC) $(CC_FLAGS) $(OBJECTS) -o shell


rshell: $($OBJECTS)
	$(CC) $(CC_FLAGS) $(OBJECTS) -o shell


test.o : shell.h
shell.o : shell.h

