# My third makefile
SHELL = /bin/sh

# Name of the project
PROJ_NAME=pmt
	
# .c files
CPP_SOURCE=$(wildcard ./*.cpp)
	
# .h files
HPP_SOURCE=$(wildcard ./*.hpp)
	
# Object files
OBJ=$(subst .cpp,.o,$(CPP_SOURCE))
	
# Compiler and linker
CC=g++
	
# Flags for compiler
CC_FLAGS=-c         \
	-W         \
# Command used at clean target
RM = rm -rf

all: BinFolder	$(PROJ_NAME)
	sudo cp $(PROJ_NAME) ../bin
	
	
$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '
	
./%.o: ./%.cpp ./%.hpp
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '
	
./main.o: ./main.cpp $(HPP_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '
	
BinFolder:
	@ mkdir -p ../bin
	
clean:
	@ $(RM) ./*.o $(PROJ_NAME) *~

install: all clean
uninstall:
	@ $(RM) ./*.o ../bin/$(PROJ_NAME) *~
	@ rmdir ../bin
.PHONY: all clean
