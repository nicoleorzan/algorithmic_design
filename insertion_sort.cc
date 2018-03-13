#include <stdlib.h>
#include <iostream>
 
/** This is the implementaition of the insertion sort
 *  algorithm to sort an array A
 **/

void insertion_sort(int *A, int size){//, int &begin, int &end){

  //printf("begin %i \n",begin);
  //printf("end %i \n",end);
  int k, i;
  std::cout<<"size in funciton "<<size<<std::endl;
  for (int j=1; j<size; j++){
    k = *(A+j);
    std::cout<<"k "<<k<<std::endl;
    i = j-1;
    while(i>=0 && *(A+i)>k){
      *(A+i+1) = *(A+i);
      i=i-1;
      *(A+i+1) = k;
      }
  }
    
}


int main(){

  int *A;
  int size = 7;
  
  A = (int*) malloc ( size * sizeof(int));
  
  for (int i=0; i<size; i++){
    A[i] = ( rand() % size );
    printf("%i ",A[i]);
  }
  printf("\n");

  int begin = *A;
  int end = *(A + size -1);
  printf("size %i \n",size);
  printf("begin %i \n",begin);
  printf("end %i \n",end);
  printf("&begin %p \n",&begin);
  printf("&end %p \n",&end);

  insertion_sort(A, size);
  
   for (int i=0; i<size; i++){
    printf("%i ",A[i]);
  }
  printf("\n");

  free(A);
  
  return 0;
}
