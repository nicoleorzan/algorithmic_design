#include "graph.h"
#include "BFS.cc"
#include "DFS.cc"
#include "tarjan.cc"
#include "fisher_meyer.cc"
#include "dijkstra.cc"
#include "a_star.cc"
#include "floyd_warshall.cc"
#include "queue.cc"


// NOTA: I NUMERI DEI VERTICI DEVONO PARTIRE DA 1, NON DA 0

void Graph::print_admat() const {
  printf("print graph adjacency matrix:\n");
    for(int i=1; i<=SIZE; i++){
      for(int j=1; j<=SIZE; j++){
	printf("%i ",admat[i*SIZE+j]);
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

// Per inserire vertici nella matrice di adiacenza
void Graph::insert_admat(int const i, int const j) {
  if ((i<1 || i>SIZE) && (j<1 || j>SIZE)){
    printf("size out of the limit!!");
    return;
  }
  else {
    admat[i+SIZE*j] = 1;
    admat[j+SIZE*i] = 1;
    admat[j+SIZE*j] = 1; //il nodo puo` sempre raggiungere se stesso
    admat[i+SIZE*i] = 1; //il nodo puo` sempre raggiungere se stesso
  }
}

// Per inserire vertici con direzione da i a j.
// I vertici vengono ovviamente inseriti anche nella matrice di adiacenze
void Graph::insert_reach(int const  i, int const j, int const w) { //i reaches j
  if ((i<1 || i>SIZE) && (j<1 || j>SIZE)){
    printf("size out of the limit!!");
    return;
  }
    reach[i*SIZE+j] = w;
    admat[i*SIZE+j] = 1;
    admat[j*SIZE+i] = 1; //<======== aggiunto questo
    admat[i*SIZE+i] = 1; //<======== aggiunto questo
    admat[j*SIZE+j] = 1; //<======== aggiunto questo 
    return;
}

//per svuotare il grafo
void Graph::clear(){
  delete[] admat;
  delete[] reach;
}




// ==================================================
//         FUNZIONI PER TESTARE GLI ALGORITMI 
// ==================================================
void BFS_DFS(){
  printf("\n======== BREADTH FIRST SEARCH and DEPTH FIRST SEARCH ========\n\n");
  Graph g1(7);
  // metto pesi tutti=1, tanto non vengono usati da BFS e DFS
  g1.insert_reach(2,3,1); 
  g1.insert_reach(4,3,1);  
  g1.insert_reach(4,2,1); 
  g1.insert_reach(2,1,1);
  g1.insert_reach(2,7,1);
  g1.print_reach();
  g1.print_admat();
  
  int s = 4;
  BFS(g1, s);
  DFS(g1);
}

void Tarjan_and_FisherMeyer(){
  printf("\n========= TARJAN: =========\n");
  Graph g1(7);
  // metto pesi tutti=1, tanto non vengono usati da Tarjan
  g1.insert_reach(2,3,1); 
  g1.insert_reach(3,4,1); 
  g1.insert_reach(4,2,1); 
  g1.insert_reach(2,1,1);
  g1.insert_reach(2,7,1);
  g1.print_reach();
  g1.print_admat();
  
  adjacency_list *ad= tarjan_scc(g1);
  printf("\n==== Printing strong connected components of the graph: ====\n");
  ad->print_list();
  printf("\nREVERSING SCC:");
  ad->reverse();
  ad->print_list();

  printf("\n============= FisherMeyer ===========\n");
  FisherMeyer(g1, ad);

}

void Dijkstra_and_Astar(){
  printf("\n======== DIJKSTRA and A_STAR: ========\n\n");
  Graph g1(5);
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
  int s=1, t=5;
  dijkstra(g1, s);
  a_star(g1, s, t);
}

void Floyd_Warshall(){
  printf("\n======== FLOYD_WARSHALL: ========\n\n");
  Graph g2(8);
  g2.insert_reach(1,6,2);
  g2.insert_reach(1,3,4);
  g2.insert_reach(1,4,18);
  g2.insert_reach(1,2,1);
  g2.insert_reach(2,3,3); 
  g2.insert_reach(2,5,6); 
  g2.insert_reach(3,4,1); 
  g2.insert_reach(3,5,2); 
  g2.insert_reach(3,8,45); 
  g2.insert_reach(5,4,2);
  g2.insert_reach(2,7,1);
  g2.insert_reach(2,8,20);
  g2.insert_reach(4,8,1);
  g2.insert_reach(5,8,2); 

  floyd_warshall(g2.get_reach_mat(), g2.SIZE);
}




int main(){

  BFS_DFS();

  //Tarjan_and_FisherMeyer();
      
  //Dijkstra_and_Astar();

  //Floyd_Warshall();
  
  printf("END\n");
  return 0;  
}
