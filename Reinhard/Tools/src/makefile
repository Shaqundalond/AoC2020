# Makefile for AoC-Tools Library Project
# Reinhard Pfaff 13.12.2020


#TMAC:
CC= g++
CFLAGS= -c -std=c++14
OExt=o
AR=ar
TARGET=AoC-Lib.a
#	$(MAKE) $(TARGET)

# the Objectfiles
objects = AoC-Tools.$(OExt)

# Rule for compiling Cpp files
%.$(OExt): %.cpp
	$(CC) $(CFLAGS) $<

# NOW the target
$(TARGET): $(objects)
	$(AR) rcs $(TARGET) $(objects)

# Target for cleaning up 
clean:
	rm *.$(OExt) 

deploy:
	mkdir -p ../../include 
	cp *.h ../../include
	mkdir -p ../../Lib
	cp *.a ../../Lib