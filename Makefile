SRC = $(wildcard *.cc)
CC = g++
CCFLAGS = -g -std=c++11 -Wall -Wextra -fopenmp
EXE = $(SRC:.cc=.x)

all: $(EXE)

%.x: %.cc
	$(CC) -o $@ $^ $(CCFLAGS)

clean: 
	@rm -rf *~ *.x

.PHONY: clean all
