#include "../BinaryHeap/binaryheap.cc"
#include "../BinaryHeap/binaryheap.h"
//#include "../../ad_exam/c++/include/btree.h"
#include "../../ad_exam/c++/src/btree.cc"

#include <vector>
//#include <stdlib.h>

void initialize_single_source(int* pi, int* d, Graph g, int s){
  for (int v=0;v<SIZE;v++){
    d[v] = 9999;
    pi[v] = 0;
  }
  d[s] = 0;
  pi[s] = s;
}

void Dijkstra(Graph g, int s){
  int* d = (int*) malloc(SIZE*sizeof(int));
  int* pi = (int*) malloc(SIZE*sizeof(int));
  initialize_single_source(pi, d, g, s);


  std::vector<int> v{1,2,3,4,7}; //nodi di g
  //BinaryHeap<int, compar> heap{v};


}
