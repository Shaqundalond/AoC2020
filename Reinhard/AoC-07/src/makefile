# Makefile for AoC Projects
# Reinhard Pfaff 03.12.2020

# Windows or MAC (does it work this way??)
#TWIN:
#	CC= cl
#	CFLAGS= -c
#	OExt=obj
#	TARGET=AoC.exe
#	$(MAKE) $(TARGET)

#TMAC:
CC= g++
CFLAGS= -c -std=c++14
OExt=o
TARGET=AoC
#	$(MAKE) $(TARGET)

# the Objectfiles
objects = AoC-07.$(OExt) AoC-Tools.$(OExt) Bag.$(OExt)

# Rule for compiling Cpp files
%.$(OExt): %.cpp
	$(CC) $(CFLAGS) $<

# NOW the target
$(TARGET): $(objects)
	$(CC) $(objects) -o $@

# Target for cleaning up 
clean:
	rm *.$(OExt) 