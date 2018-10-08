#include "graph.h"
#include "queue.cc"
#include "adjacency_list.cc"
//#include "../BinaryHeap/binaryheap.h"
#include "DFS.cc"
#include "BFS.cc"
#include "tarjan.cc"
//#include "coll.cc"
//#include "dijkstra.cc"
#include "floyd_warshall.cc"

// NOTA: I NUMERI DEI VERTICI DEVONO PARTIRE DA 1, NON DA 0

void Graph::print_admat() const {
  printf("print graph adjacecncy matrix:\n");
    for(int i=1; i<=SIZE; i++){
      for(int j=1; j<=SIZE; j++){
	printf("%i ",admat[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
}

void Graph::print_reacmat() const {
  printf("print graph reachability matrix:\n");
    for(int i=1; i<=SIZE; i++){
      for(int j=1; j<=SIZE; j++){
	printf("%i ",reac_mat[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
}

void Graph::print_weights() const {
  printf("print graph weights matrix:\n");
    for(int i=1; i<=SIZE; i++){
      for(int j=1; j<=SIZE; j++){
	printf("%i ",weights[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
}


void Graph::insert_admat(int i, int j) {
  if ((i<1 || i>SIZE) && (j<1 || j>SIZE)){
    printf("size out of the limit!!");
    return;
  }
  else {
    admat[i+SIZE*j] = 1;
    admat[j+SIZE*i] = 1;
    admat[j+SIZE*j] = 1; //il nodo puo` sempre ragigungere se stesso
    admat[i+SIZE*i] = 1; //il nodo puo` sempre ragigungere se stesso
  }
}

void Graph::insert_weight(int i, int j, int w){
   if ((i<1 || i>SIZE) && (j<1 || j>SIZE)){
    printf("size out of the limit!!");
    return;
   }
    else if (i==j){
      printf("cannot weight a node\n");
      return;
    }
    else{
      weights[i+SIZE*j] = w;
      weights[j+SIZE*i] = w;
    }
}

void Graph::insert_reacmat(int i, int j) { //i reaches j
  if ((i<1 || i>SIZE) && (j<1 || j>SIZE)){
    printf("size out of the limit!!");
    return;
  }
   else if (i==j){
    reac_mat[i+SIZE*j] = 1;
    admat[i+SIZE*j] = 1;
  }
  else{
    reac_mat[i+SIZE*j] = -1;
    reac_mat[j+SIZE*i] = 1;
    reac_mat[j+SIZE*j] = 1; //il nodo puo` sempre ragigungere se stesso
    reac_mat[i+SIZE*i] = 1;
    admat[i+SIZE*j] = 1;
    admat[j+SIZE*i] = 1;
    admat[j+SIZE*j] = 1; //il nodo puo` sempre ragigungere se stesso
    admat[i+SIZE*i] = 1; //il nodo puo` sempre ragigungere se stesso
  }
}


void Graph::clear(){
  free(admat);
  free(reac_mat);
}

int main(){
  Graph g1;
  /* \\for collapse:
  g1.insert_reacmat(2,3); 
  g1.insert_reacmat(3,4); 
  g1.insert_reacmat(4,2); 
  g1.insert_reacmat(2,1);
  g1.insert_reacmat(2,7);
  
  g1.print_reacmat();
  g1.print_admat();*/
  
  /*printf("\n==== BFS and DFS: ====\n");
   int s = 4;
    BFS(g1, s);*/
  //DFS(g1);
  
  adjacency_list *ad= tarjan_scc(g1);
  printf("\n==== Printing strong connected components of the graph: ====\n");
  ad->print_list();
  //let's reverse the sccs:
  int * scc_arr = (int*) malloc (SIZE*SIZE*sizeof(int));
  int * reversed_scc = (int*) malloc (SIZE*SIZE*sizeof(int));
  ad->list_to_array(scc_arr);

  int k=0;
  for (int i=SIZE-1; i>=0; i--){
    if (scc_arr[i]!=0){
    for (int j=0; j<SIZE; j++){
      reversed_scc[k+SIZE*j] = scc_arr[i+SIZE*j];
      }
    k++;
    }
  }
  //adjacency_list* rev = new(adjacency_list);
  int size_reversed_scc=0;
  printf("REVERSED SCC:\n");
  for (int i=0; i<SIZE; i++){
    if (reversed_scc[i]!=0){
      size_reversed_scc++;
      printf("v=%i ", reversed_scc[i]);
      //rev->add_node(reversed_scc[i]);
      for (int j=1; j<SIZE; j++){
	if (reversed_scc[i+SIZE*j]!=0){
	  printf("v=%i ", reversed_scc[i+SIZE*j]);
	  //printf("adding to %i\n", reversed_scc[i]);
	  //rev->add_neighbor(reversed_scc[i],reversed_scc[i+SIZE*j]);
	}
      }
      printf("\n");
    }
  }
  //printf("REVERSED LIST SCC:\n");
  //rev->print_list();

  
  //adjacency_list *adjr =
  //collapse(g1, reversed_scc, size_reversed_scc);
  //printf("\n==== Printing adjrh: ====\n");
  //adjr->print_list();

  /*printf("\n!!!!!!!!!!!!!!!!! Dijkstra  !!!!!!!!!!!!!!!!\n");
  int s=1;
  Dijkstra(g1, s);
  free(reversed_scc);
  free(scc_arr);*/

  printf("\n!!!!!!!!!!!!!!!!! Floyd Warshall  !!!!!!!!!!!!!!!!\n");
  g1.insert_reacmat(1,6);
  g1.insert_reacmat(1,3);
  g1.insert_reacmat(1,4);
  g1.insert_reacmat(1,2);
  g1.insert_reacmat(2,3); 
  g1.insert_reacmat(2,5); 
  g1.insert_reacmat(3,4); 
  g1.insert_reacmat(3,5); 
  g1.insert_reacmat(3,8); 
  g1.insert_reacmat(5,4);
  g1.insert_reacmat(2,7);
  g1.insert_reacmat(2,8);
  g1.insert_reacmat(4,8);
  g1.insert_reacmat(5,8);
  g1.insert_weight(1,6,2);
  g1.insert_weight(2,5,6);
  g1.insert_weight(1,4,18);
  g1.insert_weight(1,3,4);
  g1.insert_weight(3,4,1);
  g1.insert_weight(2,3,3);
  g1.insert_weight(1,2,1);
  g1.insert_weight(3,8,45);
  g1.insert_weight(5,4,2);
  g1.insert_weight(4,8,1);
  g1.insert_weight(2,7,1);
  g1.insert_weight(3,5,2);
  g1.insert_weight(2,8,20);
  g1.insert_weight(5,8,2);
 
  g1.print_weights();
  printf("size of the graph= %i\n",SIZE);

  
  int * W = g1.get_weight_mat();

  floyd_warshall(W);
  
  printf("END\n");
  return 0;  
}
