# Makefile for Fresh Prints
# Aaron Van Cleave
# Last Modified 21 Dec 2020

CC = gcc
CFLAGS = -W -Wall
OBJECTS = demo.o generic_prints.o silly_prints.o
PROGRAMS = demo

all: $(PROGRAMS)

# Compile
demo: $(OBJECTS)
	$(CC) $(OBJECTS) -o demo

.o:
	$(CC) $(CFLAGS) -c $<

# Execute
run: $(PROGRAMS)
	./$(PROGRAMS)

# Clean up
clean:
	rm -f $(PROGRAMS) $(OBJECTS)
