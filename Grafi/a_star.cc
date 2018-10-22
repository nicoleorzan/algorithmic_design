#include "queue.cc"

void print_mat(int *arr, int SIZE){
  for (int v=1; v<=SIZE; v++){
    for (int w=1; w<=SIZE; w++){
      printf("%i ", arr[v*SIZE+w]);
    }
    printf("\n");
  }
}

void print_arr(int *arr, int SIZE){
  for (int v=1; v<=SIZE; v++){
      printf("%i ", arr[v]);
    }
  printf("\n");
}


void rebuilt_path(int * pi, int t, int s, int size){
  printf("\n====Rebuild path====\n");
  printf("pi array:\n");
  print_arr(pi, size);
  queue * total_path = new queue();
  int current = t;
  total_path->enqueue(t);
  while(current!=s){
    current = pi[current];
    total_path->enqueue(current);
  }
  printf("printing (reversed) total path:\n");
  total_path->print_queue();
  
}

void initialize_single_source(int* pi, int s, queue *priority, int *h, int t, int* d, int SIZE){
  printf("\n====Initialize single source====\n");
  for (int v=1; v<=SIZE; v++){
    for (int w=1; w<=SIZE; w++){
      if (v>w) h[v*SIZE+w] = v-w; 
      else h[v*SIZE+w] = w-v; 
    }
    if (v!=s){
      priority->enqueue_dijkstra(v, 99999);
      pi[v] = 0;
      d[v] = 99999;
    }
  }
  priority->enqueue_dijkstra(s,h[s*SIZE+t]);
  d[s] = 0;
  pi[s] = s;
  printf("--- heuristic distance matrix:\n");
  print_mat(h, SIZE);
  /*printf("--- pi arr:\n");
  print_arr(pi, SIZE);
  printf("--- d arr:\n");
  print_arr(d, SIZE);
  printf("--- initial priority queue:\n");
  priority->print_priority();
  printf("\n");*/
}


void a_star(Graph g, int s, int t){ // s is the source and t is the destination in the graph
  printf("\n\n========= A* algorithm =========\n\n");
  printf("we choose s=%i, t=%i\n", s, t);
  int* pi = new int[(g.SIZE+1)*sizeof(int)];
  int* d = new int[(g.SIZE+1)*sizeof(int)];
  int* h = new int[(g.SIZE+1)*(g.SIZE+1)*sizeof(int)];
  queue *priority = new queue();
  queue *S = new queue();
  int z = s;
  
  initialize_single_source(pi, s, priority, h, t, d, g.SIZE);
    
  while(priority->is_empty()!=1){
    //priority->print_priority();
    //printf("printing pi:\n");
    //print_arr(pi);
    z = priority->extract_min();
    priority->dequeue_from_value(z);
    //printf("extracting z=%i\n", z);
    S->enqueue(z);
    if (z == t){
      rebuilt_path(pi, t, s, g.SIZE);
    }
    else{
      for (int u=1; u<=g.SIZE; u++){
	if (g.reach[z*g.SIZE+u]!=0 && priority->value_already_present(u)==1){
	  if (d[u] > d[z]+g.reach[z*g.SIZE+u]){
	    d[u] = d[z]+g.reach[z*g.SIZE+u];
	    pi[u] = z;
	    priority->update_priority(u, d[u]+h[u*g.SIZE+z]);
	  }
	}
      }
    }
  }
  printf("===end===\n\n");

  delete[] pi;
  delete[] h;
  delete[] d;

}
