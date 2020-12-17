# Makefile for AoC Projects
# Reinhard Pfaff 17.12.2020

CC= g++
CFLAGS= -c -g -std=c++14 -I../../Include
OExt=o
TARGET=AoC
LIBS=../../Lib/AoC-Lib.a

# the Objectfiles
objects = AoC.$(OExt)

# Rule for compiling Cpp files
%.$(OExt): %.cpp
	$(CC) $(CFLAGS) $<

# NOW the target
$(TARGET): $(objects)
	$(CC) $(objects) $(LIBS) -o $@

# Target for cleaning up 
clean:
	rm *.$(OExt) 