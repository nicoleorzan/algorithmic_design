#include <iostream>
#define SIZE 5

#ifndef __GRAPH__
#define __GRAPH__

class Graph{

 private:
 
     
 public:
  
  int *admat;

  Graph(){
    admat = (int*) malloc(SIZE*SIZE*sizeof(int) );
    for( int i = 0; i < SIZE*SIZE; i++ ){
      admat[i] = 0;
    }
  }
  ~Graph(){
    free(admat);
  }

  void print() const;
  void insert(int i, int j);
  void clear();

}; // end class Graph

#endif
