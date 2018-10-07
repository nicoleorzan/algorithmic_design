#include "adjacency_list.cc"

adjacency_list* collapse(Graph g, int *mn, int mn_size){
  printf("\n========collapse=======\n");
  int *vtom = (int*)malloc(SIZE*sizeof(int));
  adjacency_list* adjr(new adjacency_list());
  queue *coda = new queue();

  int i=0;
  int node = 0;
  printf("size=%i\n",mn_size);
  while(i<mn_size){
    for (int vv=0; vv<SIZE; vv++){
      printf("vv=%i\n", vv);
      if (mn[vv+SIZE*node]!=0){
	printf("filling vtom[%i] = %i\n", vv, i);
	vtom[vv] = i;
	adjr->add_node(i);
	printf("---> got coda\n");
	for (int ii=1; ii<SIZE; ii++){
	  if (mn[vv+SIZE*ii]!=0)
	    coda-> enqueue(mn[vv+SIZE*ii]);
	}
	coda->print_queue();
	if (coda->is_empty()==0){
	  printf("coda size=%i\n",coda->return_size());
	  for (int v=0; v<coda->return_size(); v++){
	    //printf("i=%i\n",i);
	    printf("coda(v=%i)= %i   ",v,coda->get_from_key(v));
	    vtom[coda->get_from_key(v)] = i;
	    adjr->add_node(i);
	    printf("filling vtom[%i] = %i \n", coda->get_from_key(v), i);
	  }
	  i++;
	}
	i++;
      }
      else {printf("---> got nothing\n");}
    }
    node++;
  }
  
   for (int v=0; v<SIZE; v++){
     printf("vtom[%i] = %i  ", v, vtom[v]);
   }
   printf("\nprinting adjr:\n");
   adjr->print_list();
   /* for (int v=0; v<mn_size; v++){
      vtom[v] = i;
      printf("vtom[%i]=%i\n",v,i);
    }
    adjr->add_node(i);
    i++;
    }
  printf("size of adjr=%i\n",adjr->return_size());
  //g.print_admat();*/

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
