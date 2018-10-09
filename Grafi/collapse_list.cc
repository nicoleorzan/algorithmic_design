#include "adjacency_list.cc"
#include <math.h> 


void matrix_multiplication(int* A, int* B, int* D_tmp, int size){
  
  for (int i=1; i<=size; i++){
    for (int j=1; j<=size; j++){
      for (int k=1; k<=size; k++){
	D_tmp[size+size+j+i]+=A[i*size+k]*B[k*size+j]; //TO FIX!!!!!!!!
      }
    }
  }
  
}

void adjl_to_adjm(adjacency_list * ad, int* mat, int size){
  //int *m = (int*) malloc (ad->return_size()*ad->return_size()*sizeof(int));
  
  for (int v=1; v<=size; v++){
    for (int w=1; w<=size; w++){
      mat[w*size+v] = 1;
    }
  }
  //return m;
}

int* ut_matrix_tc_real(int *m, int size){
  if (size==1) return m;

  int *A = (int*) malloc (size*size*sizeof(int));
  int *B = (int*) malloc (size*size*sizeof(int));
  int *C = (int*) malloc (size*size*sizeof(int));

  free(A);
  free(B);
  free(C);

  return A;
}

void ut_matrix_tc(int *m, int size){
  if (log(size)!=std::floor(log(size))){
    m = ut_matrix_tc_real(m, size);
  }
}

adjacency_list* collapse(Graph g, adjacency_list *mn){
  printf("\n========collapse=======\n");
  int mn_size = mn->return_size();
  int *vtom = (int*)malloc((SIZE+1)*sizeof(int));
  adjacency_list* adjr(new adjacency_list());
  queue *coda = new queue();

  for (int v=1; v<=SIZE; v++){
     vtom[v]=0;
   }
  
  //VTOM PARTE DA 1!!
  int i=1;
  int node = 0;
  printf("mn_size=%i\n\n",mn_size);
  while(i<=mn_size){
    node=mn->get_val_from_key(i);
    //printf("node=%i\n",node);
    vtom[node] = i;
    coda = mn->get_node_from_key(i)->neighbors;
    if (coda->is_empty()!=1){
      for (int v=0; v<coda->return_size(); v++){
	//printf("coda->get_from_key(v+1) = %i\n", coda->get_from_key(v+1));
	vtom[coda->get_from_key(v+1)]=i;
      }
    }
    i++;
  }

   for (int v=1; v<=SIZE; v++){
     printf("vtom[%i]=%i\n", v, vtom[v]);
     //ogni scc ha un nuovo numero da 1 a mn size che sarebbe il nome di lui se fosse un "nodo" solo
   }
   printf("\n");
   
   for (int v=1; v<=SIZE; v++){
     for (int w=1; w<=SIZE; w++){
       if(g.admat[v+SIZE*w]!=0){
	 if(adjr->get_node(vtom[v])==nullptr){
	   adjr->add_node(vtom[v]);
	   }
	 if (vtom[w]!=vtom[v] && adjr->get_node(vtom[v])->neighbors->value_already_present(vtom[w])!=1 ){
	   adjr->add_neighbor(vtom[v], vtom[w]);
	 }
       }
     }
   }
   
   adjr->print_list();

   int * adjm = (int*)malloc((mn_size+1)*(mn_size+1)*sizeof(int));
   adjl_to_adjm(adjr, adjm, mn_size);
   
   free(vtom);
   return adjr;
  
}
