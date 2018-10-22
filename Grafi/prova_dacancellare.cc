#include "stdio.h"
void print_mat(int* A, int dim){
  //PRINT STARTS FROM 1!!!!
  for(int i=1; i<=dim; i++){
    for(int j=1; j<=dim; j++){
      printf("%i ",A[i*dim+j]);
    }
    printf("\n");
  }
}

void matrix_multiplication(int* A, int* B, int* D_tmp, int size){

  for (int i=1; i<=size; i++){
    for (int j=1; j<=size; j++){
      for (int k=1; k<=size; k++){
	D_tmp[j+i*size]+=A[i*size+k]*B[k*size+j];
      }
    }
  }
  
}

int main(){
  
  int size= 4;

  int * A =new int[(size+1)*(size+1)*sizeof(int)]
  int * B = new int[(size+1)*(size+1)*sizeof(int)];
  int * D_tmp = new int[(size+1)*(size+1)*sizeof(int)];

  for (int i=1; i<=size; i++){
    for (int j=1; j<=size; j++){
      A[i*size+j] = 1;
      B[i*size+j] = 1;
      D_tmp[i*size+j] = 0;
    }
  }
  printf("printing A\n");
  print_mat(A, size);
  printf("printing B\n");
  print_mat(B, size);
  matrix_multiplication(A, B, D_tmp, size);
  printf("printing D_tmp\n");
  print_mat(D_tmp, size);

  delete[] A;
  delete[] B;
  delete[] D_tmp;
  
return 0;
}
