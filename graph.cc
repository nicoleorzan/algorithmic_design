#include <iostream>
#include "graph.h"

//#define SIZE 10


/*class Graph{

 private:
  
  int *admat;
    
 public:
  Graph(){
    admat = (int*) malloc(SIZE*SIZE*sizeof(int) );
    for( int i = 0; i < SIZE*SIZE; i++ ){
      admat[i] = 0;
    }
  }
  

  void print() const{
    std::cout<<"print graph adjacecncy matrix:"<<std::endl;
    for(int i=0; i<SIZE; i++){
      for(int j=0; j<SIZE; j++){
	printf("%d ",admat[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
  }// end print
  
}; //end class Graph
*/

void Graph::print() const {
std::cout<<"print graph adjacecncy matrix:"<<std::endl;
    for(int i=0; i<SIZE; i++){
      for(int j=0; j<SIZE; j++){
	printf("%d ",admat[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
}

int main(){
  Graph g1;
  g1.print();

  return 0;  
}
