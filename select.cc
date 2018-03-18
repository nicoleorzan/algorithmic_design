#include <stdlib.h>
#include <iostream>
#include <math.h>

#define SIZE 55
#define VAR 23
// This is the implementaition of the select algorithm to
// take an unsorted array A, and extract the j-th element
// of the sorted one

/* FUNCTION DECLARATIONS */

template<typename K>
int selectt(K *A, int begin_index, int end_index, int j);

template<typename K>
int select_pivot(K *A, int begin, int end);

template<typename K>
std::pair<int,int> tripartition(K *A, int begin_index, int end_index,int  pivot);

/* END FUNCTION DECLARATIONS  */





template<typename K>
void insertion_sort(K *A, int begin, int end){
  
  std::cout<<"-----INSERTION SORT-----"<<std::endl;
  int k, i;
  for (int j=begin+1; j<end+1; j++){
    k = *(A+j);
    i = j-1;
    while(i>=begin && *(A+i)>k){
      *(A+i+1) = *(A+i);
      i=i-1;
      *(A+i+1) = k;
    }
  }
  
    
}

template<typename K>
int selectt(K *A, int begin_index, int end_index, int j){

  std::cout<<"------SELECT------"<<std::endl;
  int size = end_index - begin_index + 1;
  if (size < 5){
    std::cout<<"size<5"<<std::endl;
    insertion_sort(A, begin_index, end_index);
    return A[j];
    }
  int piv =  select_pivot(A, begin_index, end_index);
  std::cout<<"pivot: "<<piv<<std::endl;
  std::pair<int,int> kpair = tripartition(A, begin_index, end_index, piv);
  std::cout << "kpair.first "<<kpair.first<< ", kpair.second "<<kpair.second<<std::endl;

  if (j <= kpair.first){
    int a = selectt(A, begin_index, kpair.first, j);
  return a;
  }
  if (j >= kpair.second){
    int b = selectt(A, kpair.second, end_index, j);
  return b;
  }
  if (j>kpair.first && j<kpair.second)  return A[j];

  return A[j];

}

template<typename K>
int select_pivot(K *A, int begin, int end){
  std::cout<<"begin "<<begin<<std::endl;
  std::cout<<"end "<<end<<std::endl;
  std::cout<<"-----SELECT PIVOT-----"<<std::endl;
  int num_of_blocks = ceil((end-begin+1)/5.); //divido array in blocchi di size 5
  
  std::cout<<"num of blocks: "<<num_of_blocks<<std::endl;
  K *medians;

  medians = new K [num_of_blocks];  

  int cbegin, cend;
  for(int i=0; i<num_of_blocks; i++){
    std::cout<<"i "<<i<<std::endl;
    cbegin = begin + 5*i;
    std::cout<<"cbegin(index)  "<<cbegin<<std::endl;
    if( cbegin+4<=end )  cend=cbegin+4;
    else cend = end;
    std::cout<<"cend(index)  "<<cend<<std::endl;
    std::cout<<"calling insertion sort from select_pivot "<<std::endl;
    insertion_sort(A, cbegin, cend);
    medians[i] = A[((cend+cbegin)/2)];
    std::cout<<"medians[i]=A[(cend+cbegin)/2.]= "<< medians[i] <<std::endl;
  }
  
  /*std::cout<<"medians "<<medians<<std::endl;
  for (int k=0; k<num_of_blocks; k++){
    std::cout<<"k="<<k<< ", medians["<<k<<"]="<<medians[k]<<std::endl;
  }
  printf("\n");*/
  //std::cout<<"(1+num_of_blocks)/2="<< (1+num_of_blocks)/2<<std::endl;
  int return_val;
  if( (1+num_of_blocks)/2==1) return_val = selectt(medians, 0, num_of_blocks, (1+num_of_blocks)/2 );
  else return_val = selectt(medians, 0, num_of_blocks-1, (1+num_of_blocks)/2 );

  std::cout<<"returning pivot value "<<return_val<<std::endl;
  
  return return_val;
  
  delete[] medians;
}


template<typename K>
std::pair<int,int> tripartition(K *A, int begin_index, int end_index, int pivot){

  std::cout<<"-----TRIPARTITION OF THE ARRAY----"<<std::endl;
    
  std::pair<int,int> p;
  int k1, k2;
  K temp;

  int i = begin_index-1;
  for (int j=begin_index; j<=end_index; j++){
    if (A[j]<pivot) {
      i++;
      temp = A[j];
      A[j] = A[i];
      A[i] = temp;
    }
    k1 = i;
  }

  for (int j=begin_index; j<=end_index; j++){
    if (A[j]==pivot) {
      i++;
      temp = A[j];
      A[j] = A[i];
      A[i] = temp;
    }
    k2 = i+1;
  }

  std::cout<<"returning k1(index, not value) "<<k1<<", (index, not value)k2 "<<k2<<std::endl;
  p.first = k1;
  p.second = k2;
  
  return p;
}



int main(){

  int *A;
  int size = SIZE;
  
  A = new int [size];  
  
  int i=0;
  while(i<size){
    A[i] = rand() % size;
    i++;
  }
    /*
int r=0, j;
std::cout<<"i "<<i<<std::endl;
    for( j=0; j<i; j++){
      if( r == A[j] )
	break;
    }
    if( j == i ){
      A[i] = r;
      i++;
      }*/
  
  for (int i=0; i<size; i++){
    printf("%i ",A[i]);
  }
  printf("\n");
  
  int begin_index = 0, end_index = size - 1;

  int var = VAR;
  
  std::cout<<"I want the value number "<<var<< " of the sorted array (start counting from 0)"<<std::endl;
  
  int value = selectt(A, begin_index, end_index, var);

  for (int i=0; i<size; i++){
    printf("%i ",A[i]);
  }
  printf("\n");
  
  std::cout<<"final value "<<value<<std::endl;

  insertion_sort(A, begin_index, end_index);
  
  for (int i=0; i<size; i++){
    printf("%i ",A[i]);
  }
  printf("\n");
  std::cout<<"EXACT FINAL VALUE "<<A[var]<<std::endl;
  
  delete[] A;
  
  return 0;
}
