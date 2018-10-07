#include <iostream>
#include <cstring>
#include <stdio.h>
//#define DEBUG

void compute_prefix_function(int* pi, char* P){
  printf("\n===compute_prefix_function===\nPrefix=");

  for (unsigned int o=0; o<strlen(P); o++){
    std::cout<<P[o];
  }
  printf("\n");
  
  int k=0;
  for (unsigned int i=1; i<strlen(P); i++){
#ifdef DEBUG
    printf("i=%i, ",i+1);
    printf("k=%i\n",k);
    printf("P[%i+1] = %c, P[%i] = %c\n",k, P[k],i+1, P[i]);
#endif
      while (k>0 && P[i]!=P[k]){
      k = pi[k];
    }
    if (P[i]==P[k]){
      k++;
    }
    pi[i] = k;
#ifdef DEBUG
    printf("pi[%i]=%i\n",i+1, k);
#endif
  }
  
}

int knuth_morris_pratt(char *T, char* P){
  printf("\n====knutt-morris-pratt====\n");

  int* pi = (int*)malloc(strlen(P)*sizeof(int));
   for(unsigned int i=0;i<strlen(P);i++){
    pi[i] = 0;
  }
  compute_prefix_function(pi, P);


  
  unsigned int i=0;
   for (unsigned int s = 0; s <= strlen(T) ; s++){
#ifdef DEBUG
     printf("s=%i, ",s);
     printf("i=%i\n",i);
#endif
     while( i>0 && T[s]!=P[i]){
#ifdef DEBUG
       printf("while\n");
       printf("i=pi[i] = pi[%i]=%i\n", i-1, pi[i-1]);
#endif
       i = pi[i-1];
     }
     if (P[i]==T[s]) {
#ifdef DEBUG
       printf("if P[i]==T[s]\n");
#endif
       i++;
     }
     if (i==strlen(P)) {
       printf("pattern occurs with shift %i\n", s-i+1);
       return s-i+1;
     }
   }

   
   printf("\nPi:\n");
   for(unsigned int o=0; o<strlen(P); o++){
     printf("%i ",pi[o]);
   }
   free(pi);
   return -99999;

}

int main(){

  char T[25]{"ABCXABCDABXABCDABCDABCY"};
  char P[10]="ABCDABCY";
  printf("O(|T|+|P|) = %zu\n", strlen(T) + strlen(T));
  int s = knuth_morris_pratt(T, P);

   std::cout<<"from SS="<<s<<" I found the string:\n";
  
   for (unsigned int i=s; i<strlen(T);i++){
     std::cout<<*(T+i);
   }
   printf("\n");
  return 0;
}
