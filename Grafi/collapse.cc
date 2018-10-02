int collapse(Graph g, int* mn){
  
  int i=0;
  int *vtom = (int*)malloc(SIZE*sizeof(int));
  queue adjr;
  //int *adjr = (int*)malloc(SIZE*sizeof(int));
  
  while(i<SIZE){
    for (int v=0; v<i; v++){
      vtom[v] = i;      
    }
    //adjr[i] = 0;
    i++;
  }

  /*for (int v=0; v<SIZE; v++){
    for (int w=0; v<i; v++){
      if(g.admat[w]!=0){
	
      }
    }
    }*/
  free(vtom);
  return 1;//adjr;
  
}
