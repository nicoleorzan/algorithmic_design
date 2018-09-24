#include <iostream>
#define SIZE 10

#ifndef __GRAPH__
#define __GRAPH__

class Graph{

 private:
  
  int *admat;
    
  public:
  Graph(){
    admat = (int*) malloc(SIZE*SIZE*sizeof(int) );
    for( int i = 0; i < SIZE*SIZE; i++ ){
      admat[i] = 0;
    }
  }

  void print() const;

};

#endif
