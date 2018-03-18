#include <stdlib.h>
#include <iostream>

/*
strassens' algorithm to multiply matrices. If the two matrices hasn't owen size, it adds a line an a column and multiplies the two matrices with a white row and column more.
*/

#define SIZE 9

template<typename K>
void print_mat(int P, int M, K * matr){
  for(int j = 0; j < P; j++ ){
    for(int i = 0; i < M; i++ ){
      //printf("%0.1f ",matr[i+j*M]);
      printf("%i ",matr[i+j*M]);
    }
    printf("\n");
  }
  printf("\n");
  
}

template<typename K>
bool check_mat(K * A, K * B, int P){
  
  for (int i=0;i<P;i++){
    for (int j=0;j<P;j++){
      if (A[i+j*P] != B[i+j*P]){
	std::cout<<"DIVERSE!!"<<std::endl;
	return 1;
      }
    }
  }
  std::cout<<"le matrici sono uguali"<<std::endl;
  return 0;

}

template<typename K>
void mult_mat(K * res, K * D, K * E, int N,  int M){
    
  for (int i=0;i<M;i++){
    for (int j=0;j<M;j++){
      for (int k=0;k<N;k++){
	res[j+i*N]+=D[i*N+k]*E[k*M+j];
      }
    }
  }

  
}


template<typename K>
void strassen(K* A, K* B, K* C, int size){
  
  int N;
  if (size%2==0) {
    N = size/2;
  }
  else  return;
  K *A11, *A12, *A21, *A22, *B11, *B12, *B21, *B22, *C11, *C12, *C21, *C22;
  K *S1, *S2, *S3, *S4, *S5, *S6, *S7, *S8, *S9, *S10, *P1, *P2, *P3, *P4, *P5, *P6, *P7;
  
  A11 = new K[N*N];
  A21 = new K[N*N];
  A12 = new K[N*N];
  A22 = new K[N*N];
  B11 = new K[N*N];
  B21 = new K[N*N];
  B12 = new K[N*N];
  B22 = new K[N*N];
  C11 = new K[N*N];
  C21 = new K[N*N];
  C12 = new K[N*N];
  C22 = new K[N*N];
  std::cout<<"here"<<std::endl;
  
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      A11[i+j*N] = A[i+j*size];
      A21[i+N*j] = A[i+(j+N)*size];
      A12[i+N*j] = A[(i+N)+j*size];
      A22[i+N*j] = A[(i+N)+(j+N)*size];
      B11[i+j*N] = B[i+j*size];
      B21[i+N*j] = B[i+(j+N)*size];
      B12[i+N*j] = B[(i+N)+j*size];
      B22[i+N*j] = B[(i+N)+(j+N)*size];
      C11[i+j*N] = C[i+j*size];
      C21[i+N*j] = C[i+(j+N)*size];
      C12[i+N*j] = C[(i+N)+j*size];
      C22[i+N*j] = C[(i+N)+(j+N)*size];
    }
  }
  
  S1 = new K[N*N];
  S2 = new K[N*N]; 
  S3 = new K[N*N]; 
  S4 = new K[N*N]; 
  S5 = new K[N*N]; 
  S6 = new K[N*N]; 
  S7 = new K[N*N]; 
  S8 = new K[N*N]; 
  S9 = new K[N*N]; 
  S10 = new K[N*N];
  
  P1 = new K[N*N];
  P2 = new K[N*N]; 
  P3 = new K[N*N]; 
  P4 = new K[N*N]; 
  P5 = new K[N*N]; 
  P6 = new K[N*N]; 
  P7 = new K[N*N];

   for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      S1[i+j*N] = 0;
      S2[i+j*N] = 0;
      S3[i+j*N] = 0;
      S4[i+j*N] = 0;
      S5[i+j*N] = 0;
      S6[i+j*N] = 0;
      S7[i+j*N] = 0;
      S8[i+j*N] = 0;
      S9[i+j*N] = 0;
      S10[i+j*N] = 0;
      P1[i+j*N] = 0;
      P2[i+j*N] = 0;
      P3[i+j*N] = 0;
      P4[i+j*N] = 0;
      P5[i+j*N] = 0;
      P6[i+j*N] = 0;
      P7[i+j*N] = 0;
    }
   }

   for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      S1[i+j*N] = B12[i+j*N]  - B22[i+j*N] ;
      S2[i+j*N] = A11[i+j*N]  + A12[i+j*N] ;
      S3[i+j*N] = A21[i+j*N]  + A22[i+j*N] ;
      S4[i+j*N] = B21[i+j*N]  - B11[i+j*N] ;
      S5[i+j*N] = A11[i+j*N]  + A22[i+j*N] ;
      S6[i+j*N] = B11[i+j*N]  + B22[i+j*N] ;
      S7[i+j*N] = A12[i+j*N]  - A22[i+j*N] ;
      S8[i+j*N] = B21[i+j*N]  + B22[i+j*N] ;
      S9[i+j*N] = A11[i+j*N]  - A21[i+j*N] ;
      S10[i+j*N] = B11[i+j*N]  + B12[i+j*N] ;      
    }
  }

  mult_mat(P1, A11, S1, N, N);
  mult_mat(P2, S2, B22, N, N);
  mult_mat(P3, S3, B11, N, N);
  mult_mat(P4, A22, S4, N, N);
  mult_mat(P5, S5, S6, N, N);
  mult_mat(P6, S7, S8, N, N);
  mult_mat(P7, S9, S10, N, N);
    
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      C11[i+j*N] = P5[i+j*N] + P4[i+j*N] - P2[i+j*N] + P6[i+j*N];
      C12[i+j*N] = P1[i+j*N] + P2[i+j*N];
      C21[i+j*N] = P3[i+j*N] + P4[i+j*N];
      C22[i+j*N] = P5[i+j*N] + P1[i+j*N] - P3[i+j*N] - P7[i+j*N];
    }
  }

  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      C[i+j*size] = C11[i+j*N];
      C[i+(j+N)*size] = C21[i+N*j];
      C[(i+N)+j*size] = C12[i+N*j];
      C[(i+N)+(j+N)*size] = C22[i+N*j];
    }
  }
  
  delete[] A11;
  delete[] A12;
  delete[] A21;
  delete[] A22;
  
  delete[] B11;
  delete[] B12;
  delete[] B21;
  delete[] B22;
  
  delete[] C11;
  delete[] C12;
  delete[] C21;
  delete[] C22;

  delete[] S1;
  delete[] S2;
  delete[] S3;
  delete[] S4;
  delete[] S5;
  delete[] S6;
  delete[] S7;
  delete[] S8;
  delete[] S9;
  delete[] S10;

  delete[] P1;
  delete[] P2;
  delete[] P3;
  delete[] P4;
  delete[] P5;
  delete[] P6;
  delete[] P7;

}

int main(){

  int *A, *B, *C, *C_TRUE;
  int size;
  if (SIZE%2!=0) size = SIZE+1;
  else size = SIZE;
  
  A = new int[size*size];
  B = new int[size*size];
  C = new int[size*size];
  C_TRUE = new int[size*size];

  for (int i=0; i<size; i++){
    for (int j=0; j<size; j++){
      A[i+j*size] = rand() % SIZE;
      B[i+j*size] = rand() % SIZE;
      //if (i==j)  B[i+j*size] = 1;
      //else B[i+j*size] = 0;
      C[i+j*size] = 0;
      C_TRUE[i+j*size] = 0;
      if(size!=SIZE && (i==size-1 || j==size-1)){
	A[i+j*size] = 0;
	B[i+j*size] = 0;
      }
    }
  }
  std::cout<<"matrix A"<<std::endl;
  print_mat(size, size, A);

  std::cout<<"matrix B"<<std::endl;
  print_mat(size, size, B);

  strassen(A, B, C, size);
  
  std::cout<<"matrix C"<<std::endl;
  print_mat(size,size,C);

  std::cout<<"matrix C_TRUE"<<std::endl;
  mult_mat(C_TRUE, A, B, size, size);
  print_mat(size,size,C_TRUE);


  check_mat(C, C_TRUE, size);
  
  delete[] A;
  delete[] B;
  delete[] C;
  delete[] C_TRUE;
  return 0;
}
