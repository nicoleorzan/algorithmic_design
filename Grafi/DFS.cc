template<typename T>
void print_char(T A){
  for(int i=0; i<SIZE; i++){
    printf("%c ",A[i]);
  }
  printf("\n");
}
template<typename T>
void print_array(T A){
  for(int i=0; i<SIZE; i++){
    printf("%i ",A[i]);
  }
  printf("\n");
}


void DFS_visit(Graph g, int u, char *color, int time, int* d, int *pi, int* f){
  printf("calling DFS_visit with u=%i \n", u);
  printf("time: %i, vector color: ",time);
  print_char(color);

  time++;
  d[u] = time;
  color[u] = 'g';

  for(int v=0; v<SIZE; v++){
    if (g.admat[v+u*SIZE]!=0){
      if (color[v] == 'w'){
	pi[v] = u;
	DFS_visit(g, v, color, time, d, pi, f);   
      }
    }
  }
  color[u] = 'b';
  time++;
  f[u] = time;
  //printf("exiting with u=%i \n", u);
  
} 

void DFS(Graph g){
  printf("================= \n");
  printf("Depth-First Search algorithm\n");
  printf("================= \n");

  int *d = (int*) malloc(SIZE*sizeof(int) );
  int *pi = (int*) malloc(SIZE*sizeof(int) );
  char *color = (char*) malloc(SIZE*sizeof(char) );
  int *f = (int*) malloc(SIZE*sizeof(int) );
  int time =0;

  printf("initialization\n"); 
  for(int u=0; u<SIZE; u++){ 
    color[u] = 'w';
    pi[u] = 0;
  }
  printf("vector color inizialmente: ");
  print_char(color);


  for(int u=0; u<SIZE; u++){
    if (color[u] =='w'){
      DFS_visit(g, u, color, time, d, pi, f);
    }
  }

  printf("vector color alla fine: ");
  print_char(color);
  printf("vector f alla fine: ");
  print_array(f);

  free(d);
  free(pi);
  free(color);
  free(f);
}
