void print_mat(int *mat){
for (int k=1; k<=SIZE; k++){
    for (int i=1; i<=SIZE; i++){
      printf("%i ", mat[i+k*SIZE]);
    }
    printf("\n");
  }
}
