//#define DEBUG
#include "adjacency_list.cc"
#include "queue.cc"
// non posso usare il valore 0 nel grafo!!


#ifndef PRINT
#define PRINT
template<typename T>
void print_char(T* A, int dim){
  for(int i=1; i<dim; i++){
    printf("%c ",A[i]);
  }
  printf("\n");
}

template<typename T>
void print_array(T* A, int dim){
  for(int i=1; i<dim; i++){
    printf("%i ",A[i]);
  }
  printf("\n");
}
#endif

int tarjan_scc_real(Graph g, int v, int &time, queue &q, int* d, int* lowlink, char* color, adjacency_list *sccs){
#ifdef DEBUG
  printf("---tarjan scc real, v=%i, time=%i---\n", v, time);
#endif
  d[v] = time;
  lowlink[v] = time;
  time++;
  color[v] ='g';
  q.enqueue(v);
#ifdef DEBUG
  print_char(color,SIZE);
  print_array(d,SIZE);
  print_array(lowlink, SIZE);
#endif


  for (int w=1; w<=g.SIZE; w++){
    if( g.reach[w+g.SIZE*v]==1){
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
  print_array(lowlink, g.SIZE);
  print_array(d, g.SIZE);
  q.print_queue();
#endif
  color[v] = 'b';
  if (lowlink[v]==d[v] && q.is_empty()==0){
    queue scc;
    //printf("--------->SCC for v=%i\n",v);
    w = q.dequeue_last_getting_val();
    fixed=w;
    if (sccs->node_already_present(w)==0) {
      sccs->add_node(w);
    }
    while(w!=v){
      scc.enqueue(w);
      w = q.dequeue_last_getting_val();
      sccs->add_neighbor(fixed,w); //qui puo` aggiungere neighbors al niente? sisi
    }
    scc.enqueue(w);
    // end if w not in scc precedenti
    //printf("Printing scc:\n");
    //scc.print_queue();
    //printf("Printing q:\n");
    //q.print_queue();
  }
#ifdef DEBUG
  scc.print_queue();
  q.print_queue();
  print_char(color, g.SIZE);
  printf("exiting\n");
#endif
  
  return time;
}



adjacency_list* tarjan_scc(Graph g){
  printf("====Tarjan scc====\n");
  int* d = new int[g.SIZE*sizeof(int)];
  int* lowlink = new int[g.SIZE*sizeof(int)];
  char* color = new char[g.SIZE*sizeof(char)];
  queue q;
  int edges=0;
  int time=0;
  adjacency_list* sccs(new adjacency_list());
  
  for (int i=1; i<=g.SIZE; i++){
    for (int j=1; j<=g.SIZE; j++){
      if (g.admat[i+g.SIZE*j]!=0) edges++;
    }
    color[i] = 'w';
    d[i]=0;
    lowlink[i] = 999;
  }
  printf("time should be~=%d\n", edges/2+g.SIZE);
  
  for (int v=1; v<=g.SIZE; v++){
    //  int v=1;
    if (color[v]=='w' && g.admat[v+g.SIZE*v]!=0){
      time = tarjan_scc_real(g, v, time, q,  d, lowlink, color, sccs);
    }
  }
  
  printf("time=%i\n", time);
  //sccs->print_list();
  delete[] d;
  delete[] lowlink;
  delete[] color;

  return sccs;
}
