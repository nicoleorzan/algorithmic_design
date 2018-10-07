#include "adjacency_list.cc"

void collapse(Graph g, int *mn, int mn_size){
  printf("\n========collapse=======\n");
  int *vtom = (int*)malloc(SIZE*sizeof(int));//the fill of vtom starts from one 
  adjacency_list* adjr(new adjacency_list());

  int i=0, vtom_counter=0, y=0;
  int node = 0;
  printf("size=%i\n",mn_size);
  while(i<mn_size){
    printf("in while, i=%i\n", i);
    y=0;
      if (mn[i+y*SIZE]!=0){
	vtom[mn[i+y*SIZE]] = i;
	vtom_counter++;
	printf("mn[i*SIZE]=%i\n",mn[i+y*SIZE]);
        y=1;
	while(mn[i+y*SIZE]!=0){
	  printf("enqueuigg %i\n",mn[i+y*SIZE] );
	  vtom[mn[i+y*SIZE]] = i;
	  y++;
	}
    }
    i++;
  }

   for (int v=1; v<SIZE; v++){
     printf("vtom[%i] = %i  ", v, vtom[v]);
   }

   for (int v=1; v<SIZE; v++){
     for (int w=1; w<SIZE; w++){
       if(g.reac_mat[v+SIZE*w]==1){
	 adjr->add_neighbor(vtom[v], vtom[w]);
	 printf("adding %i to %i  \n", vtom[v], vtom[w]);
	 }
       }
   }
     adjr->print_list();   


  
}
