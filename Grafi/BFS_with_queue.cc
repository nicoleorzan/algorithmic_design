//#define DEBUG
#include "queue.cc"

template<typename T>
void print_char(T* A, int dim){
  for(int i=0; i<dim; i++){
    printf("%c ",A[i]);
  }
  printf("\n");
}

template<typename T>
void print_array(T* A, int dim){
  for(int i=0; i<dim; i++){
    printf("%i ",A[i]);
  }
  printf("\n");
}

void BFS(Graph g, int s){
  printf("================= \n");
  printf("Breadth First Search algorithm\n");
  printf("================= \n");
  
  printf("selected vertex number %i (counting from 1) \n", s);
  s=s-1;
  int *d = (int*) malloc(SIZE*sizeof(int) );
  int *pi = (int*) malloc(SIZE*sizeof(int) );
  char *color = (char*) malloc(SIZE*sizeof(char) );
  queue q;
  int u;

#ifdef DEBUG
  printf("vector q inizialmente:\n");
  q.print_queue();
#endif
 
  // initialization
   for(int i=0; i<SIZE; i++){
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
   print_char(color, SIZE);
#endif
   
   q.enqueue(s);
   q.print_queue();
   while(q.is_empty()==0){
     u = q.dequeue_last_getting_val();
#ifdef DEBUG
     printf("u=%i \n", u );
#endif
     for(int v=0; v<SIZE; v++){
       if (g.admat[v+SIZE*u]!=0){
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

   printf("color: ");
   print_char(color, SIZE);
   printf("dist: ");
   print_array(d, SIZE);
   printf("pi: ");
   print_array(pi, SIZE);
   
   free(d);
   free(pi);
   free(color);
}
