CC = g++
C11 = -std=c++11
CC_FLAGS = -Wall -Werror -pedantic
OBJECTS = test.cpp shell.cpp Base.cpp

all: $(OBJECTS)
	$(CC) $(C11) $(CC_FLAGS) $(OBJECTS) -o shell


rshell: $(OBJECTS)
	$(CC) $(C11) $(CC_FLAGS) $(OBJECTS) -o shell

clean: $(OBJECTS)
	rm -f test.o shell.o Base.o

