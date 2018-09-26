//#include <iostream>
#include "graph.h"
#define SIZE 5
#include "DFS.cc"
#include "BFS.cc"
//#include "dijkstra.cc"

void Graph::print() const {
  printf("print graph adjacecncy matrix:\n");
    for(int i=0; i<SIZE; i++){
      for(int j=0; j<SIZE; j++){
	printf("%i ",admat[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
}

void Graph::insert(int i, int j) {
  if ((i<0 || i>=SIZE) && (i<0 || i>=SIZE)){
    printf("size out of the limit!!");
    return;
  }
  else {
    admat[i+SIZE*j] = 1;
    admat[j+SIZE*i] = 1;
  }
}

void Graph::clear(){
  free(admat);
}

int main(){
  Graph g1;
  //g1.print();
  g1.insert(0,4);
  g1.insert(2,4);
  g1.insert(1,3);
  g1.insert(4,5);
  g1.insert(4,1);
  g1.insert(1,2);
  g1.print();
  g1.clear();

  int s = 4;
  //BFS(g1, s);
  DFS(g1);
  //Dijkstra(g1);

  
  return 0;  
}

