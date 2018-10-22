#include <iostream>
//#define SIZE 5

#ifndef __GRAPH__
#define __GRAPH__

class Graph{

 private:
 
 void insert_admat(int i, int j);
     
 public:
  
  int *admat;
  int *reach;
  int *reached;
  int SIZE;

  Graph(int siz){
 		SIZE=siz;
    admat = new int[(SIZE+1)*(SIZE+1)*sizeof(int)]; 
    //(int*) malloc((SIZE+1)*(SIZE+1)*sizeof(int) );
    reach = new int[(SIZE+1)*(SIZE+1)*sizeof(int)]; 
    reached = new int[(SIZE+1)*(SIZE+1)*sizeof(int)]; 	
    for( int i = 1; i <= SIZE*SIZE; i++ ){
      admat[i] = 0;
      reach[i] = 0;
      reached[i] = 0;
    }
  }
  ~Graph(){
    //delete[] admat;
    //delete[] reach;
    //delete[] reached;
  }

  void print_admat() const;
  void print_reach() const;
  void print_reached() const;	
  void insert_reach(int i, int j, int w);	
  void insert_reached(int i, int j, int w);		
  void clear();
  int* get_admat() {return this->admat;};
  int* get_reach_mat() {return this->reach;};

}; // end class Graph

#endif
