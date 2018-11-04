#ifndef PRINT
#define PRINT

// PRINT OF ARRAYS AND MATRICES STARTS FROM 1
void print_matrix(int const *mat, int const SIZE){
for (int k=1; k<=SIZE; k++){
    for (int i=1; i<=SIZE; i++){
      printf("%i ", mat[i+k*SIZE]);
    }
    printf("\n");
  }
}

template<typename T>
void print_char(T* const A, int const dim){
  for(int i=1; i<=dim; i++){
    printf("%c ",A[i]);
  }
  printf("\n");
}

template<typename T>
void print_array(T* const A, int const dim){
  for(int i=1; i<=dim; i++){
    printf("%i ",A[i]);
  }
  printf("\n");
}

#endif
