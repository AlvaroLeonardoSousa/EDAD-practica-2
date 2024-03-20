CC=gcc
CFLAGS=-Wall -ggdb
IFLAGS=-I./
LDFLAGS=-L./
CLIB1= -lstack2 -L.
CLIB2= -lstack -L.
LIBS = -lm 

.PHONY: clean_objects clean_program clean all

all: p2_e1 p2_e2 p2_e3 p2_e1extra

alls: p2_e1s p2_e2s p2_e3s

##############################################

p2_e1.o: p2_e1.c stack.h maze.h
	$(CC) $(CFLAGS) -c $<

p2_e2.o: p2_e2.c stack.h maze.h
	$(CC) $(CFLAGS) -c $<

p2_e3.o: p2_e3.c stack.h maze.h search.h
	$(CC) $(CFLAGS) -c $<

##############################################

p2_e1: p2_e1.o maze.o libstack.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

p2_e2: p2_e2.o maze.o libstack.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

p2_e3: p2_e3.o search.o maze.o libstack.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

##############################################

p2_e1extra: p2_e1extra.c elements.h
	$(CC) -o $@ $< 

##############################################

p2_e1s: p2_e1.o maze.o libstack2.a
	$(CC) -o $@ $^ $(CLIB2) $(LIBS)

p2_e2s: p2_e2.o maze.o libstack2.a
	$(CC) -o $@ $^ $(CLIB2) $(LIBS)

p2_e3s: p2_e3.o search.o maze.o libstack2.a
	$(CC) -o $@ $^ $(CLIB2) $(LIBS)

libstack2.a: stack.o 
	ar rcs $@ $^

###############################################
search.o: search.c search.h
	$(CC) $(CFLAGS) -c $<

maze.o: maze.c maze.h
	$(CC) $(CFLAGS) -c $<

stack.o: stack.c   
	$(CC) $(CFLAGS) -c $<
#################################################

valgrind: 
	valgrind --leak-check=full 

#################################################

clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f p2_e1 p2_e2 p2_e3 p2_e1s p2_e2s p2_e3s p2_e1extra 

clean: clean_objects clean_program

