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


int tarjan_scc_real(Graph g, int v, int &time, queue &q, int* d, int* lowlink, char* color, adjacency_list &sccs){
  printf("tarjan scc real, v=%i, time=%i\n", v, time);
  d[v] = time;
  lowlink[v] = time;
  time++;
  color[v] = 'g';
  q.enqueue(v);
#ifdef DEBUG
  print_char(color,SIZE);
  print_array(d,SIZE);
  print_array(lowlink, SIZE);
#endif


  for (int w=0; w<SIZE; w++){
    if( g.reac_mat[w+SIZE*v]==1){
      if (color[w]=='w'){
	time = tarjan_scc_real(g, w, time, q, d, lowlink, color, sccs);
	if (lowlink[v]>lowlink[w]) { lowlink[v] = lowlink[w];}
#ifdef DEBUG
	printf("size of q=%i\n",q.return_size());
	q.print_queue();
#endif
      }
      else if(color[w]=='g'){
	if (lowlink[v]>lowlink[w]) { lowlink[v] = lowlink[w];}
      }
    }
  }

  
  int w;
  int fixed;
#ifdef DEBUG
  printf("=======root node=======, v=%i\n", v);
  printf("CHECK LOWLINK OF V=%i\n", v);
  print_array(lowlink, SIZE);
  print_array(d, SIZE);
  q.print_queue();
#endif
  color[v] = 'b';
  if (lowlink[v]==d[v] && q.is_empty()==0){
    queue scc;
    printf("--------->SCC for v=%i\n",v);
    w = q.dequeue_last_getting_val();
    fixed=w;
    // if w not in scc precedenti -> maybe iterator over values
    //printf("sccs size=%i\n",sccs.return_size());
    sccs.add_node(w); 
    while(w!=v){
      //sccs.enqueue(w);
      scc.enqueue(w);
      w = q.dequeue_last_getting_val();
      sccs.add_neighbor(fixed,w);
    }
    //sccs.enqueue(w);
    scc.enqueue(w);
    // end if w not in scc precedenti
    printf("printing scc\n");
    scc.print_queue();
    printf("printing q\n");
    q.print_queue();
  }
  #ifdef DEBUG
  scc.print_queue();
  q.print_queue();
  print_char(color, SIZE);
  printf("exiting\n");
  #endif
  
  return time;
}



void tarjan_scc(Graph g){
  printf("tarjan scc\n");
  int* d = (int*)malloc(SIZE*sizeof(int));
  int* lowlink = (int*)malloc(SIZE*sizeof(int));
  char* color = (char*)malloc(SIZE*sizeof(char));
  queue q;
  int edges=0;
  int time=0;
  //queue sccs;
  adjacency_list sccs;
  
  for (int i=0; i<SIZE; i++){
    for (int j=0; j<SIZE; j++){
      if (g.admat[i+SIZE*j]!=0) edges++;
    }
    color[i] = 'w';
    d[i]=0;
    lowlink[i] = 999;
  }
  printf("time should be~=%d\n", edges/2+SIZE);
  
  for (int v=0; v<SIZE; v++){
    if (color[v]=='w'){
      int v = 4;
      time = tarjan_scc_real(g, v, time, q,  d, lowlink, color, sccs);
    }
  }
  
  printf("time=%i\n", time);
  sccs.print_list();
  free(d);
  free(lowlink);
  free(color);
}
