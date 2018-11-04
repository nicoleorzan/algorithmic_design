#include <iostream>
//#define SIZE 5

#ifndef __GRAPH__
#define __GRAPH__

class Graph{

 private:
 
 void insert_admat(int const i, int const j);
     
 public:
  
  int *admat;
  int *reach;
  int SIZE;

  Graph(int siz){
    SIZE = siz;
    admat = new int[(SIZE+1)*(SIZE+1)*sizeof(int)]; 
    reach = new int[(SIZE+1)*(SIZE+1)*sizeof(int)]; 
    //initialization    
    for( int i = 1; i <= SIZE*SIZE; i++ ){
      admat[i] = 0;
      reach[i] = 0;
    }
  }
  ~Graph(){
    //delete[] admat;
    //delete[] reach;
  }

  void print_admat() const;
  void print_reach() const;
  void insert_reach(int const i, int const j, int const w);			
  void clear();
  int* get_admat() const {return this->admat;};
  int* get_reach_mat() const {return this->reach;};

};//end Graph

#endif
