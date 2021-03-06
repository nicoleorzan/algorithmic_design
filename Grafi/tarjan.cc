//#define DEBUG
#include "adjacency_list.cc"
#include "queue.cc"
#include "print.cc"
// non posso usare il valore 0 nel grafo!!


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
  print_char(color, g.SIZE);
  print_array(d,g.SIZE);
  print_array(lowlink, g.SIZE);
#endif


  for (int w=1; w<=g.SIZE; w++){
    if( g.reach[w+g.SIZE*v]==1){ //admat -> reach
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
  sccs->print_list();//s
  q.print_queue();
  print_char(color, g.SIZE);
  printf("exiting\n");
#endif
  
  return time;
}



adjacency_list* tarjan_scc(Graph g){
  printf("====Tarjan scc====\n");

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

  
  int* d = new int[g.SIZE*sizeof(int)];
  int* lowlink = new int[g.SIZE*sizeof(int)];
  char* color = new char[g.SIZE*sizeof(char)];
  queue q;
  int time=0;
  adjacency_list* sccs(new adjacency_list());
  
  for (int i=1; i<=g.SIZE; i++){
    color[i] = 'w';
    d[i]=0;
    lowlink[i] = 999;
  }
  
  for (int v=1; v<=g.SIZE; v++){
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
