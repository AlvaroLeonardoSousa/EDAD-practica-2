CC=gcc
CFLAGS=-Wall -ggdb
IFLAGS=-I./
LDFLAGS=-L./
CLIB= -lstack -L.
LIBS = -lm -pthread

.PHONY: clean_objects clean_program clean all

all: p2_e1

##############################################

p2_e1: p2_e1.o maze.o libstack.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

p2_e1.o: p2_e1.c stack.h maze.h
	$(CC) $(CFLAGS) -c $<

maze.o: maze.c maze.h
	$(CC) $(CFLAGS) -c $<



#################################################

clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f anthill

clean: clean_objects clean_program