#include <iostream>

class Dynamic_array{

  int size;
  int *A;
  
public:
  Dynamic_array(int eleme[], int q): size{q}{
    A = (int*) malloc(q*sizeof(int));
    for (int i=0; i<q; i++){
      A[i] = eleme[i];
      //printf("eleme[%i] = %i \n",i, eleme[i]);
    }
}
  ~Dynamic_array(){
    free(A);
  };
  int get_size() const { return size; }
  void print_vector() const;
  void push_back(int el[], int plus);
  void push_head(int el[], int plus);

};

void Dynamic_array::print_vector() const {
  printf("=======print_vector======= ");

  printf("size of the array %i\n", size);
  for (int i=0; i<size; i++){
    printf("A[%i] = %i\n", i, *(A+i));
  }
}

void Dynamic_array::push_back(int el[], int plus){
   printf("=======push_back=======\n");
   int *A_new = (int*)malloc((size+plus)* sizeof(int));
   for (int i=0; i<size; i++){
     A_new[i] = A[i];
   }
   for (int i=0; i<plus; i++){
     A_new[i+size] = el[i];
   }

   for (int i=0; i<size+plus; i++){
     A[i] = A_new[i];
   }
   size = size+plus;
   free(A_new); 
}

void Dynamic_array::push_head(int el[], int plus){
  printf("=======push_head=======\n");
  int *A_new = (int*)malloc((size+plus)* sizeof(int));
  for (int i=0; i<plus; i++){
    A_new[i] = el[i];
  }
  for (int i=0; i<size; i++){
    A_new[i+plus] = A[i];
  }
  for (int i=0; i<size+plus; i++){
    A[i] = A_new[i];
  }
  size = size+plus;
  free(A_new); 
}

int main(){
  int siz = 3;
  int el[siz]{5,6,7};
  Dynamic_array a(el, siz);

  printf("dim= %i \n", a.get_size());
  a.print_vector();

  int siz2 = 4;
  int el2[siz2]{1,2,3,4};
  
  a.push_back(el2, siz2);
  a.print_vector();

  int ee[1]{66};
  int si = 1;
  a.push_head(ee, si);
  a.print_vector();
  return 0;
}
