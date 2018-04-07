CXX = c++
CFLAGS = -g -std=c++14 -Wall -Wextra -fopenmp
IFLAGS = -I .

all: binaryheap.x

binaryheap.x: binaryheap.o
	$(CXX) -o $@ $^ $(CFLAGS) $(IFLAGS)

binaryheap.o: binaryheap.cc
	$(CXX) -c -o $@ $^ $(CFLAGS) $(IFLAGS)

clean:
	@rm -rf *~ *.x *.o 

.PHONY: clean
