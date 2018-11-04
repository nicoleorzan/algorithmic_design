#include "print.cc"

void DFS_visit(Graph g, int u, char *color, int time, int* d, int *pi, int* f){
  printf("calling DFS_visit with u=%i \n", u);
  printf("time: %i, vector color: ",time);
  print_char(color, g.SIZE);
  printf("vector d: ");
  print_array(d, g.SIZE);
  printf("vector f: ");
  print_array(f, g.SIZE);

  time++;
  d[u] = time;
  color[u] = 'g';

  for(int v=1; v<=g.SIZE; v++){
    if (g.admat[v+u*g.SIZE]!=0){
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
  printf("================= \n\n");

  int *d = new int[(g.SIZE+1)*sizeof(int) ];
  int *pi = new int[(g.SIZE+1)*sizeof(int) ];
  char *color = new char[(g.SIZE+1)*sizeof(char) ];
  int *f = new int[(g.SIZE+1)*sizeof(int) ];
  int time =0;

  printf("initialization\n"); 
  for(int u=1; u<=g.SIZE; u++){ 
    color[u] = 'w';
    pi[u] = 0;
    d[u] = 999;
    f[u] = 999;
  }
  printf("vector color inizialmente: ");
  print_char(color, g.SIZE);


  for(int u=1; u<=g.SIZE; u++){
    if (color[u] =='w'){
      DFS_visit(g, u, color, time, d, pi, f);
    }
  }

  printf("vector color alla fine: ");
  print_char(color, g.SIZE);
  printf("vector f alla fine: ");
  print_array(f, g.SIZE);

  delete[] d;
  delete[] pi;
  delete[] color;
  delete[] f;
  printf("\n\n\n\n");
}
