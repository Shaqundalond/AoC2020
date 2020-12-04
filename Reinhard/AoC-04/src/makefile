# Makefile for AoC Projects
# Reinhard Pfaff 03.12.2020

CC= g++
CFLAGS= -c

objects = AoC-03.o AoC-Tools.o

# Rule for compiling Cpp files
%.o: %.cpp
	$(CC) $(CFLAGS) $<

# first target (default if no other target is specified)
AoC: $(objects)
	$(CC) $(objects) -o $@

# Target for cleaning up 
clean:
	rm *.o 