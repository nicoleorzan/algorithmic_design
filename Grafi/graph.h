#include <iostream>
#define SIZE 5

#ifndef __GRAPH__
#define __GRAPH__

class Graph{

 private:
 
 void insert_admat(int i, int j);
     
 public:
  
  int *admat;
  int *reac_mat;
  int *weights;
	int *reached;

  Graph(){
    admat = (int*) malloc((SIZE+1)*(SIZE+1)*sizeof(int) );
    reac_mat = (int*) malloc((SIZE+1)*(SIZE+1)*sizeof(int) );
    reached_mat = (int*) malloc((SIZE+1)*(SIZE+1)*sizeof(int) );	
    weights = (int*) malloc((SIZE+1)*(SIZE+1)*sizeof(int) );	
    for( int i = 1; i <= SIZE*SIZE; i++ ){
      admat[i] = 0;
      reac_mat[i] = 0;
      reached[i] = 0;
      weights[i] = 0;
    }
  }
  ~Graph(){
    //free(admat);
    //free(reac_mat);
    //free(weights);
  }

  void print_admat() const;
  void print_reacmat() const;
  void print_weights() const;	
  void insert_reacmat(int i, int j);	
  void insert_reached(int i, int j. int w);	
  void insert_weight(int i, int j, int w);		
  void clear();
  int* get_admat() {return this->admat;};
  int* get_weight_mat() {return this->weights;};

}; // end class Graph

#endif
