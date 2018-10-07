#include <iostream>
#define SIZE 8

#ifndef __GRAPH__
#define __GRAPH__

class Graph{

 private:
 
 void insert_admat(int i, int j);
     
 public:
  
  int *admat;
  int *reac_mat;

  Graph(){
    admat = (int*) malloc(SIZE*SIZE*sizeof(int) );
    reac_mat = (int*) malloc(SIZE*SIZE*sizeof(int) );	
    for( int i = 0; i < SIZE*SIZE; i++ ){
      admat[i] = 0;
      reac_mat[i] = 0;
    }
  }
  ~Graph(){
    //free(admat);
    //free(reac_mat);
  }

  void print_admat() const;
  void print_reacmat() const;
  void insert_reacmat(int i, int j);		
  void clear();
  int* get_admat() {return this->admat;};

}; // end class Graph

#endif
