#include <iostream>
#include <cstring>
#include <stdio.h>

void compute_prefix_function(int* pi, char* P){
  printf("compute_prefix_function\nPrefix=");

  for (unsigned int o=0; o<strlen(P); o++){
    std::cout<<P[o];
  }
  printf("\n");
  
  int k=0;
  printf("k=%i\n",k);
  for (unsigned int i=2; i<=strlen(P); i++){
    printf("i=%i, ",i);
    printf("k=%i\n",k);
    printf("P[%i+1] = %c, P[%i] = %c\n",k, P[k+1],i, P[i]);
      while (k>0 && P[i]!=P[k+i]){
      k = pi[k];
    }
    if (P[i]==P[k+1]){
      k++;
    }
    pi[i] = k;
  }
  
}

int knutt_morris_pratt(char *T, char* P){
  printf("====knutt-morris-pratt====\n");

  int* pi = (int*)malloc(strlen(P)*sizeof(int));
   for(unsigned int i=0;i<strlen(P);i++){
    pi[i] = 0;
  }
  compute_prefix_function(pi, P);
  
  unsigned int i=0;
   for (unsigned int s = 1; s <= strlen(T) ; s++){
     while( i>0 && T[s]!=P[i+1]){
       i = pi[i];
     }
     if (pi[i+1]==T[s]) i++;
     if (i==strlen(P)) {
       printf("pattern occurs with shift %i", s-i);
       i=pi[i];//?
       return s-i;
     }
   }

   for(unsigned int o=0; o<strlen(P); o++){
     printf("pi[%i] = %i ",o,pi[o]);
   }
   free(pi);
   return -99999;

}

int main(){

  char T[25]{"ABCXABCDABXABCDABCDABCY"};
  char P[10]="ABCDABCY";
  printf("O(|T|+|P|) = %zu\n", strlen(T) + strlen(T));
  int s = knutt_morris_pratt(T, P);
  printf("s=%i\n",s);
  return 0;
}
