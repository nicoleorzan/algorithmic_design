#include "adjacency_list.cc"
#include <math.h> 

#ifndef PRINTMAT
#define PRINTMAT

void print_matrix(int* A, int dim){
  //PRINT STARTS FROM 1!!!!
  for(int i=1; i<=dim; i++){
    for(int j=1; j<=dim; j++){
      printf("%i ",A[i*dim+j]);
    }
    printf("\n");
  }
}
#endif


void matrix_multiplication(int* A, int* B, int* D_tmp, int size){

  for (int i=1; i<=size; i++){
    for (int j=1; j<=size; j++){
      for (int k=1; k<=size; k++){
	D_tmp[j+i*size]+=A[i*size+k]*B[k*size+j];
      }
    }
  }
  
}

void adjl_to_adjm(adjacency_list * ad, int* mat, int size){

  for (int v=1; v<=size; v++){
    for (int w=1; w<=size; w++){
      if(ad->get_node(v)->neighbors->value_already_present(w)==1){
	mat[w*size+v] = 1;
      }
      else mat[w*size+v] = 0;
    }
  }

}

void split_three_blocks(int*A, int*B, int*C, int *m, int size){
  for (int i=1; i<=size/3; i++){
    for (int j=1; j<=size/3; j++){
      A[i*size+j] = m[i*size+j];
      B[i*size+j] = m[i*size+j];
      C[i*size+j] = m[i*size+j];
    }
  }

}

void zero_one(int *m, int size){

  for (int v=1; v<=size; v++){
    for (int w=1; w<=size; w++){
      if (m[v*size+w]!=0) m[v*size+w]=1;
    }
  }
  
}

int* ut_matrix_tc_real(int *m, int size){
  if (size==1) return m;

  int * A = new int[(size+1)*(size+1)*sizeof(int)];
  int * B = new int[(size+1)*(size+1)*sizeof(int)];
  int * C = new int[(size+1)*(size+1)*sizeof(int)];
  int * Astar = new int[(size+1)*(size+1)*sizeof(int)];
  int * Bstar = new int[(size+1)*(size+1)*sizeof(int)];
  int * D = new int[(size+1)*(size+1)*sizeof(int)];
  /*split_three_blocks(A, B, C, m, size);
    Astar = ut_matrix_tc_real(A);
    Bstar = ut_matrix_tc_real(A);
    D = matrix_multiplication(Astar, C);
    D = matrix_multiplication(D, Bstar);
    zero_one(D);
   */
  
  delete[] A;
  delete[] B;
  delete[] C;
  delete[] Astar;
  delete[] Bstar;
  delete[] D;

  return A;
}

void ut_matrix_tc(int *m, int size){
  printf("\n===ut_matrix_tc====\n");
  printf("log2(size)=%f\n", log2(size));
  printf("floor(log2(size))=%f\n", floor(log2(size)));
  if (log2(size)!=std::floor(log(size))){
    printf("yea\n");
    // m = ut_matrix_tc_real(m, size);
  }
}

/*adjacency_list* decollapse(adjacency_list * ad, int* vtom){
  printf("\n====Decollapse====\n");
  int t=1;
  int * used = new int[SIZE+1];
  for (int k=1; k<=SIZE; k++){
    used[k] =0;
  }
  
  adjacency_list* deco = new adjacency_list();
  for (int i=1; i<=SIZE; i++){
    if (vtom[i]!=0 && used[i]==0){
      used[i]=1;
      if(deco->get_node(i)==nullptr){
	//printf("adding node %i\n", i);
      deco->add_node(i);
      }
      t=i+1;
      while(t<=SIZE){
	//printf("t=%i\n", t);
	if (vtom[t]==vtom[i] && deco->get_node(i)->neighbors->value_already_present(t)!=1 ) {
	  deco->add_neighbor(i, t);
	  used[t]=1;
	}
	t++;
      }
    }
  }

  deco->print_list();
  delete[] used;
  return deco;
  }*/

adjacency_list* collapse(Graph g, adjacency_list *mn){
  printf("\n========collapse=======\n");
  int mn_size = mn->return_size();
  int * vtom = new int[(g.SIZE+1)*sizeof(int)];
  // int *vtom = (int*)malloc((SIZE+1)*sizeof(int));
  adjacency_list* adjr(new adjacency_list());
  queue *coda = new queue();

  for (int v=1; v<=g.SIZE; v++){
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

   for (int v=1; v<=g.SIZE; v++){
     printf("vtom[%i]=%i\n", v, vtom[v]);
     //ogni scc ha un nuovo numero da 1 a mn size che sarebbe il suo nome se fosse un "nodo" solo
   }
   printf("\n");
   int * scc_mat = new int[(mn_size+1)*(mn_size+1)*sizeof(int)];
   
   for (int v=1; v<=mn_size; v++){
     for (int w=1; w<=mn_size; w++){
       scc_mat[v+mn_size*w]=0;
     }
   }
   for (int v=1; v<=g.SIZE; v++){
     for (int w=1; w<=g.SIZE; w++){
       // if(g.admat[*SIZE+v]!=0){
       if(g.reach[w*g.SIZE+v]!=0){
	 printf("%i collegato con %i\n",w,v);
	 if(adjr->get_node(vtom[v])==nullptr){
	   adjr->add_node(vtom[v]);
	   }
	 if (vtom[w]!=vtom[v] && adjr->get_node(vtom[v])->neighbors->value_already_present(vtom[w])!=1 ){
	   //printf("adding %i to %i\n", vtom[w], vtom[v]);
	   adjr->add_neighbor(vtom[v], vtom[w]);
	 }
       }
     }
   }
   printf("adjr:\n");
   adjr->print_list();

   int * adjm = (int*)malloc((mn_size+1)*(mn_size+1)*sizeof(int));
   adjl_to_adjm(adjr, adjm, mn_size);
   print_matrix(adjm, mn_size);
   ut_matrix_tc(adjm, mn_size);


   // adjacency_list* decollapsed =  decollapse(adjr, vtom);
   
   delete[] vtom;
   return adjr;
  
}
