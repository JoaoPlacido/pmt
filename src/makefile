# My third makefile
SHELL = /bin/sh

# Name of the project
PROJ_NAME=pmt
	
# .cpp files
CPP_SOURCE=$(wildcard ./*.cpp)
CPP_ALGORITHMS=$(wildcard ./algorithms/*.cpp)

# .hpp files
HPP_SOURCE=$(wildcard ./*.hpp)
 
# Object files
OBJ=$(subst .cpp,.o,$(CPP_SOURCE))
ALGORITHMS_OBJ=$(subst .cpp,.o,$(CPP_ALGORITHMS))
	
# Compiler and linker
CC=g++
	
# Flags for compiler
CC_FLAGS=-c         \
	-W         \
# Command used at clean target
RM = rm -rf

all: BinFolder	$(PROJ_NAME)
	sudo cp $(PROJ_NAME) ../bin
	
	
$(PROJ_NAME): $(OBJ) $(ALGORITHMS_OBJ)
./%.o: ./%.cpp ./%.hpp
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '
	
./main.o: ./main.cpp $(HPP_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./algorithms/%.o:./algorithms/%.cpp ./algorithms/algorithms.hpp
	$(CC) $< $(CC_FLAGS) -o $@

BinFolder:
	@ mkdir -p ../bin
	
clean:
	@ $(RM) ./algorithms/*.o ./*.o $(PROJ_NAME) *~

install: all clean
uninstall:
	@ $(RM) ./*.o ../bin/$(PROJ_NAME) *~
	@ rmdir ../bin
.PHONY: all clean
