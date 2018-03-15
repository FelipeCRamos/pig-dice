# Makefile for the Pig Dice Software
#
# Creators:
# 	- Felipe Ramos
#
# Makefile conventions
SHELL = /bin/sh

# Directories
incdir = ./include
srcdir = ./src
objdir = ./obj
bindir = ./bin

# Macros
CC = g++
CFLAGS = -Wall -g -ggdb -std=c++11 -I. -I$(incdir)
RM = -rm
OBJS = $(addprefix $(objdir)/,dice.o util.o chooser.o)

# Phony targets
.PHONY: clean cleanobj cleanbin 
.PHONY: all main build dice util chooser

# Use "make" to execute everything
all: build main

# Use "make main" to compile the main
main: pigdice

# Use "make build" to build all the modules
build: util dice chooser

# Use "make <name>" to build only the <name> module
util: $(objdir)/util.o
dice: $(objdir)/dice.o
chooser: $(objdir)/chooser.o


# Compiles the main
pigdice: $(srcdir)/main.cpp $(OBJS)
	 mkdir -p $(bindir)
	$(CC) $(CFLAGS) $^ -o $(bindir)/$@

# Builds only the util module
$(objdir)/util.o: $(srcdir)/util.cpp $(incdir)/util.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the dice module (use "make dice")
$(objdir)/dice.o: $(srcdir)/dice.cpp $(incdir)/dice.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the dice module (use "make dice")
$(objdir)/chooser.o: $(srcdir)/chooser.cpp $(incdir)/chooser.h
	mkdir -p $(objdir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes all objects
cleanobj:
	$(RM) $(objdir)/*.o

# Clean all executables
cleanbin:
	$(RM) -rf $(bindir)/*

# Removes all executables and all objects
clean: cleanobj cleanbin
