//#define DEBUG
#include "queue.cc"

#ifndef PRINT
#define PRINT
template<typename T>
void print_char(T* A, int dim){
  for(int i=1; i<=dim; i++){
    printf("%c ",A[i]);
  }
  printf("\n");
}

template<typename T>
void print_array(T* A, int dim){
  for(int i=1; i<=dim; i++){
    printf("%i ",A[i]);
  }
  printf("\n");
}
#endif

void BFS(Graph g, int s){
  printf("================= \n");
  printf("Breadth First Search algorithm\n");
  printf("================= \n\n");
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
  printf("worst-case complexity: vert=%i, edges=%i, O(|V|+|E|)=%i\n",vert, edg, vert+edg);
  
  printf("selected vertex number %i (counting from 1) \n", s);
  s=s-1;
  int *d = new int[(g.SIZE+1)*sizeof(int) ];
  int *pi =  new int[(g.SIZE+1)*sizeof(int) ];
  char *color =  new char[(g.SIZE+1)*sizeof(char) ];
  //(char*) malloc(g.SIZE*sizeof(char) );
  queue q;
  int u;

#ifdef DEBUG
  printf("vector q inizialmente:\n");
  q.print_queue();
#endif
 
  // initialization
   for(int i=1; i<=g.SIZE; i++){
     if (i!= s){
     color[i] = 'w';
     d[i] = 999;
     pi[i] = 0;
     }
   }
   color[s] = 'g';
   d[s] = 0;
   pi[s] = 0;

#ifdef DEBUG
   printf("vector color inizialmente:\n");
   print_char(color, g.SIZE);
#endif
   
   q.enqueue(s);
   q.print_queue();
   while(q.is_empty()==0){
     u = q.dequeue_last_getting_val();
#ifdef DEBUG
     printf("u=%i \n", u );
#endif
     for(int v=1; v<=g.SIZE; v++){
       if (g.admat[v+g.SIZE*u]!=0){
	 if (color[v]=='w') {
	   color[v]='g';
	   d[v] = d[u] + 1;
	   pi[v] = u;
	   q.enqueue(v);
#ifdef DEBUG
	   printf("printing q:  ");
	   q.print_queue();
#endif
	 }
       }// end if
       color[u] = 'b';
     }
   }// end while
   printf("\nFinal output:\n");
   printf("color: ");
   print_char(color, g.SIZE);
   printf("dist: ");
   print_array(d, g.SIZE);
   printf("pi: ");
   print_array(pi, g.SIZE);
   
   delete[] d;
   delete[] pi;
   delete[] color;
   printf("\n\n\n\n");
}
