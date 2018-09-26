#define SIZE 5

void tarjan_scc(Graph g){
  int* d = (*int)malloc(SIZE*sizeof(int));
  int* lowlink = (*int)malloc(SIZE*sizeof(int));
  int* color = (*int)malloc(SIZE*sizeof(char));
  int q[SIZE]={0};
  int time=0;

  for (int i=0; i<SIZE; i++){
    color[i] = 'w';
    d[i]=0;
    lowlink[i] = 999;
  }
  
  for (int v=0; v<SIZE; v++){
    if (color[v]=='w'){
      time = tarjan_scc_real(g, v, time, q, d, lowlink, color);
    }
  }

}


int tarjan_scc_real(Graph g, int v, int time, int q, int* d, int* lowlink, int* color){
  int count = 0;
  int* tmp_scc;
  d[v] = time;
  lowlink[v] = time;
  time ++;
  color[v] = 'g';
  q[count] = v;


  for (int w=0; w<SIZE; w++){
    if( g.admat[w+SIZE*u]!=0){
      if (color[w]=='w'){
	time =  tarjan_scc_real(g, w, time, q, d, lowlink, color);
	if (lowlink[v]>lowlink[w]) { lowlink[v] = lowlink[w];}
      }
      else{ //case going through new branch
	if (color[w]=='g'){
	  if (lowlink[v]>d[w]) { lowlink[v] = d[w]; } /*not lowlink??*/
	}
      }
    }
  }
  int size;
  int* scc = (*int)malloc(1*sizeof(int));
  color[v] = 'b';
  if (lowlink[v]==d[v]){
    scc = 0;
    while(q[0] == v){
      //starting append....
      size = sizeof(scc)/sizeof(int);
      int* scc2 = (*int)malloc((size+1)*sizeof(int));
      for (int i=0; i<size; i++){
	scc2[i] = scc[i];
      }
      scc2[size] = q[0];
      free(scc);
      size = sizeof(scc2)/sizeof(int);
      int* scc = (*int)malloc((size)*sizeof(int));
      for (int i=0; i<size; i++){
	scc[i] = scc2[i];
      }
      free(scc2);
      //here ends append...maybe
      

    }    
  }

  return time;
}
