//#include <iostream>
#include "graph.h"
#include "collapse.cc"
#include "adjacency_list.cc"
//#include "DFS.cc"
#include "queue.cc"
#include "tarjan.cc"
//#include "BFS_with_queue.cc"
//#include "dijkstra.cc"

#define SIZE 4

void Graph::print_admat() const {
  printf("print graph adjacecncy matrix:\n");
    for(int i=0; i<SIZE; i++){
      for(int j=0; j<SIZE; j++){
	printf("%i ",admat[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
}

void Graph::print_reacmat() const {
  printf("print graph reachability matrix:\n");
    for(int i=0; i<SIZE; i++){
      for(int j=0; j<SIZE; j++){
	printf("%i ",reac_mat[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
}


void Graph::insert_admat(int i, int j) {
  if ((i<0 || i>=SIZE) && (j<0 || j>=SIZE)){
    printf("size out of the limit!!");
    return;
  }
  else {
    admat[i+SIZE*j] = 1;
    admat[j+SIZE*i] = 1;
  }
}

void Graph::insert_reacmat(int i, int j) { //i reaches j
  if ((i<=-SIZE || i>=SIZE) && (j<=-SIZE || j>=SIZE)){
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
    admat[i+SIZE*j] = 1;
    admat[j+SIZE*i] = 1;
  }
}


void Graph::clear(){
  free(admat);
  free(reac_mat);
}

adjacency_list* reverse(adjacency_list * old){
 adjacency_list* newlist(new adjacency_list());
 node *p = old->root;
}

int main(){
  Graph g1;
  //g1.print();
  g1.insert_reacmat(1,2); 
  g1.insert_reacmat(2,3); 
  g1.insert_reacmat(3,1); 
  g1.insert_reacmat(0,1); 
  //g1.insert_reacmat(1,4); //1 can reach 4
  //g1.insert_reacmat(4,2); //4 can reach 2
  //g1.insert_reacmat(2,1); //2 can reach 1
  //g1.insert_admat(1,3);
  //g1.insert_admat(4,5);
  //g1.insert_admat(4,1);
  //g1.insert_admat(1,2);
  g1.print_reacmat();
  g1.print_admat();
  
  /*int s = 4;
    BFS(g1, s);*/
  //DFS(g1);
  adjacency_list *ad= tarjan_scc(g1);
  printf("\n==== Printing adjacency list of the graph: ====\n");
  ad->print_list();
  //let's reverse the sccs:

  
  // adjacency_list *adjr = collapse(g1, ad);
  //printf("\n==== Printing adjr of the graph: ====\n");
  //adjr->print_list();
  printf("\nEND\n");
  
  //Dijkstra(g1);

  return 0;  
}
