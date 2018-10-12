#include "graph_modified.h"
#include "dijkstra.cc"
#include "queue.cc"

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

void Graph::print_reached() const {
  printf("print graph reached matrix:\n");
    for(int i=1; i<=SIZE; i++){
      for(int j=1; j<=SIZE; j++){
	printf("%i ",reached[i*SIZE+j]);
      }
      printf("\n");
    }
    printf("\n");
}

void Graph::print_reach() const {
  printf("print graph reach matrix:\n");
    for(int i=1; i<=SIZE; i++){
      for(int j=1; j<=SIZE; j++){
	printf("%i ",reach[i*SIZE+j]);
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


void Graph::insert_reached(int i, int j, int w){ // i is reached by j
   if ((i<1 || i>SIZE) && (j<1 || j>SIZE)){
    printf("size out of the limit!!");
    return;
   }
    reached[i+SIZE*j] = w;
    admat[i+SIZE*j] = 1;
    //admat[i+SIZE*j] = 1;
    return;
}

void Graph::insert_reach(int i, int j, int w) { //i reaches j
  if ((i<1 || i>SIZE) && (j<1 || j>SIZE)){
    printf("size out of the limit!!");
    return;
  }
    reach[i*SIZE+j] = w;
    admat[i*SIZE+j] = 1;
    // admat[j+SIZE*i] = 1;
    return;
}


void Graph::clear(){
  free(admat);
  free(reached);
  free(reach);
}

int main(){
  
  Graph g1;
  
  /* printf("\n==== BFS and DFS: ====\n");
     g1.insert_reacmat(2,3); 
     g1.insert_reacmat(3,4); 
     g1.insert_reacmat(4,2); 
     g1.insert_reacmat(2,1);
     g1.insert_reacmat(2,7);
     g1.print_reacmat();
     g1.print_admat();
  
     int s = 4;
     BFS(g1, s);
     DFS(g1);*/


  /* printf("\n==== TARJAN: ====\n");
  g1.insert_reacmat(2,3); 
  g1.insert_reacmat(3,4); 
  g1.insert_reacmat(4,2); 
  g1.insert_reacmat(2,1);
  g1.insert_reacmat(2,7);
  g1.print_reacmat();
  g1.print_admat();
  adjacency_list *ad= tarjan_scc(g1);
  printf("\n==== Printing strong connected components of the graph: ====\n");
  ad->print_list();
  printf("\nREVERSING SCC\n");
  ad->reverse();
  ad->print_list();
  */
  printf("\n!!!!!!!!!!!!!!!!! Collapse !!!!!!!!!!!!!!!!\n");
  //adjacency_list *adj_sccs = collapse(g1, ad);
  //int* m = adjl_to_adjm(adj_sccs);
  //int* m_star = ut_matrx_tc(m);
  //printf("\n==== Printing adjrh: ====\n");
  //adjr->print_list();






  
  printf("\n!!!!!!!!!!!!!!!!! Dijkstra  !!!!!!!!!!!!!!!!\n");

  g1.insert_reach(1,2,10);
  g1.insert_reach(1,3,3);
  g1.insert_reach(2,3,1);
  g1.insert_reach(3,2,4);
  g1.insert_reach(2,4,2);
  g1.insert_reach(3,5,2); 
  g1.insert_reach(3,4,8); 
  g1.insert_reach(4,5,7); 
  g1.insert_reach(5,4,9);
  
  g1.print_reach();
  g1.print_admat();
  int s=1;
  dijkstra(g1, s);
  //free(reversed_scc);
  //free(scc_arr);



  
  
  /*printf("\n!!!!!!!!!!!!!!!!! Floyd Warshall  !!!!!!!!!!!!!!!!\n");
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

  floyd_warshall(W);*/
  
  printf("END\n");
  return 0;  
}
