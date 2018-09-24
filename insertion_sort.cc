#include <iostream>
 
/** Implementaition of the insertion sort
 *  algorithm to sort an array A
 **/

//void insertion_sort(int *A, int size){
void insertion_sort(int *A, int begin_index, int end_index){

  //int size = end_index - begin_index + 1;
  printf("begin_index %i \n",begin_index);
  printf("end_index %i \n",end_index);
  int k, i;
  // std::cout<<"size in funciton "<<size<<std::endl;
  for (int j=begin_index+1; j<end_index+1; j++){
    k = *(A+j);
    // std::cout<<"k "<<k<<std::endl;
    i = j-1;
    while(i>=begin_index && *(A+i)>k){
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

  //int begin = *A;
  //int end = *(A + size -1);
  int begin_index = 0;
  int end_index = size - 1;
  printf("size %i \n",size);

  // insertion_sort(A, size);
  insertion_sort(A, begin_index, end_index);
  
   for (int i=0; i<size; i++){
    printf("%i ",A[i]);
  }
  printf("\n");

  free(A);
  return 0;
}
