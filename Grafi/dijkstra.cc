#include "queue.cc"
#include <math.h> 

void initialize_single_source(int* pi, int s, queue *priority, int size){
  for (int v=1; v<=size; v++){
    if (v!=s){
      priority->enqueue_dijkstra(v, 99999);
      pi[v] = 0;
    }
  }
  priority->enqueue_dijkstra(s,0);
  pi[s] = s;
}


void dijkstra(Graph g, int s){
  printf("============ Dijkstra ==========\n");


  int vert=0;
  int edg=0;
  for (int i=1; i<=g.SIZE; i++){
    for (int j=i; j<=g.SIZE; j++){
      if (i==j){
	if (g.admat[i+g.SIZE*j]!=0) vert++;
      }
      if( i!=j && g.admat[i+g.SIZE*j]!=0){
	edg++;
      }
    }
  }
  printf("worst-case complexity: vert=%i, edges=%i, O(|E|+|V|^2) = %i -> ",vert, edg, vert*vert+edg);
  printf("because we are using a simple queue\n");
  printf("using a Fibonacci min Heap I would have got: O( |V|log|V|+|E| ) = %f\n",  vert*log(vert) + edg );
  printf("using a Binary Heap I would have got: O( (|V|+|E|)log2|V| ) = %f\n\n\n",(vert+edg)*log2(vert));
  printf("we choose s=%i\n", s);
  int* pi = new int[g.SIZE*sizeof(int)];
  queue *S = new queue();
  queue *priority = new queue();
  int u = s;
  
  initialize_single_source(pi, s, priority, g.SIZE);
    
  while(priority->is_empty()!=1){
    //printf("printing priority queue:\n");
    //priority->print_priority();
    u = priority->extract_min();
    //printf("u=%i\n", u);
    priority->dequeue_from_value(u);
    S->enqueue(u);
    for(int v=1; v<=g.SIZE; v++){
      if (g.reach[u*g.SIZE+v]!=0 && priority->value_already_present(v)==1){
	if (g.reach[u*g.SIZE+v] < priority->get_from_value(v)->dijkstra_distance){
	  priority->update_priority(v, g.reach[u*g.SIZE+v]);
	}
      }
    }
  }
  printf("\n===printing final queue:===\n");
  S->print_queue();
  printf("===\n\n\n");
  
  delete[] pi;

}
