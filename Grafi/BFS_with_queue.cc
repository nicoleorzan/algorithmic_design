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
  queue q;//int q[SIZE]={0};

#ifdef DEBUG
  printf("vector q inizialmente:\n");
  q.print_queue();
  //print_array(q, SIZE);
  /*for(int i=0; i<SIZE; i++){
    printf("%i ",q[i]);
  }
  printf("\n");*/
#endif
  
  // int in = 0;//increment of the queue
  int u;
 
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
   printf("IN iniziale: %i \n", in );
#endif
   
   //q[in] = s;
   q.enqueue(s);
   //in++;
   //int out=0;
   //printf("OUT iniziale: %i \n", out );
   
   //printf("starting while loop \n");
   //while (out!=SIZE){
   while(q.is_empty==0)
     u = q.dequeue();
     // u = q[out];
   //out++;
#ifdef DEBUG
     printf("u=%i \n", u );
     printf("OUT increm: %i \n", out );
#endif
     for(int v=0; v<SIZE; v++){
       if (g.admat[v+SIZE*u]!=0){
	 if (color[v]=='w') {
	   color[v]='g';
	   d[v] = d[u] + 1;
	   pi[v] = u;
	   q[in]=v;
	   in++;
#ifdef DEBUG
	   printf("IN increm: %i\n",in);
	   printf("printing q:  ");
	   print_array(q, SIZE);
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
