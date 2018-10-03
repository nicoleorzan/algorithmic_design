#include "adjacency_list.cc"

adjacency_list* collapse(Graph g, adjacency_list *mn){
  printf("\n========collapse=======\n");
  int i=0;
  int mn_size = mn->return_size();
  int *vtom = (int*)malloc(SIZE*sizeof(int));
  adjacency_list* adjr(new adjacency_list());;
 
  printf("mn_size=%i\n",mn_size);
  while(i< mn_size){
    for (int v=0; v<mn_size; v++){
      vtom[v] = i;
      printf("vtom[%i]=%i\n",v,i);
    }
    //adjr[i] = 0;
    i++;
  }
  printf("size of adjr=%i\n",adjr->return_size());
  //g.print_reacmat();
  //g.print();
  for (int v=0; v<SIZE; v++){
    for (int w=0; w<SIZE; w++){
      if(g.admat[v+i*w]!=0){
	printf("here\n");
	adjr->add_neighbor(vtom[v], vtom[w]);
      }
    }
  }
  adjr->print_list();
  //free(vtom);
  return adjr;
  
}
