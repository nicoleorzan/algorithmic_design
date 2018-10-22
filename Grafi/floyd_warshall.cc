#ifndef PRINT
#def PRINT
void print_mat(int *mat, int SIZE){
for (int k=1; k<=SIZE; k++){
    for (int i=1; i<=SIZE; i++){
      printf("%i ", mat[i+k*SIZE]);
    }
    printf("\n");
  }
}

#endif

void floyd_warshall(int * W, int SIZE){
  printf("\n======floyd_warshall======\n");
  printf("Theta(V^3) = %i \n", SIZE*SIZE*SIZE);
  
  int * D =  (int*)malloc((SIZE+1)*(SIZE+1)*sizeof(int));
  D = W;
  int * pi = (int*)malloc((SIZE+1)*(SIZE+1)*sizeof(int));

  for (int i=1; i<=SIZE; i++){
    for (int j=1; j<=SIZE; j++){
      if (i==j || D[SIZE*i+j]==0){
	pi[SIZE*i+j] = 999;
      } else {
	pi[SIZE*i+j] = i;
      }
    }
  }

  printf("\nBEFORE:\n");
  printf("Matrix D:\n");
  print_mat(D, SIZE);
  printf("Matrix pi:\n");
  print_mat(pi, SIZE);
  
  for (int k=1; k<=SIZE; k++){
    for (int i=1; i<=SIZE; i++){
      for (int j=1; j<=SIZE; j++){
	if ( D[j+SIZE*i] >  D[j+SIZE*k] + D[k+SIZE*i]  && D[j+SIZE*k]!=0 && D[k+SIZE*i]) {
	  D[j+SIZE*i] =  D[j+SIZE*k] +  D[k+SIZE*i];
	  pi[j+SIZE*i] = pi[j+SIZE*k];
	}
      }
    }
  }
  printf("\nAFTER:\n");
  printf("Matrix D:\n");
  print_mat(D, SIZE);
  printf("Matrix pi:\n");
  print_mat(pi, SIZE);
  free(pi);
  free(D);
}
