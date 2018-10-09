#include "adjacency_list.cc"

adjacency_list* collapse(Graph g, adjacency_list *mn){
  printf("\n========collapse=======\n");
  int mn_size = mn->return_size();
  int *vtom = (int*)malloc((SIZE+1)*sizeof(int));
  adjacency_list* adjr(new adjacency_list());
  queue *coda = new queue();

  int i=0;
  int node = 0;
  printf("size=%i\n",mn_size);
  /* while(i<mn_size){
  mn->
  }*/
  

   for (int v=0; v<SIZE; v++){
     for (int w=0; w<SIZE; w++){
       if(g.admat[v+SIZE*w]!=0){
	 adjr->add_neighbor(vtom[v], vtom[w]);
       }
     }
   }
     adjr->print_list();
  //free(vtom);
  return adjr;
  
}
