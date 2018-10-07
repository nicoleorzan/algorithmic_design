#include <iostream>
#include <cstring>
#include <stdio.h>

int pm_naive(char* T, char* P){

  unsigned int i=0;
  int ss=-99;
  int len = strlen(T);
  printf("strlen(T)=%i, ",len);
  printf("strlen(P)=%zu\n",strlen(P));
  for (unsigned int s = 0; s <= ( strlen(T) - strlen(P) ); s++){
    i = 1;
    //std::cout<<"s= "<<s<<"\n";
    while (i<=strlen(P) && P[i]==T[s+i]){
      i++;
      //std::cout<<"i= "<<i<<"\n";
    }
    if ( i>=strlen(P) ) {
      //printf("here\n");
      ss=s;
    }
  }
  return ss;
  
}

int main(){

  //std::string cc{"ciao"};
  //char source[] = "This is an example.";
  //int len = strlen( source );
  //char* c = source;
  //while (*c) putchar(*c++);
  
  char T[25]{"ABCXABCDABXABCDABCDABCY"};
  char P[10]="ABCDABCY";
  printf("O(|T|*|P|) = %zu\n", strlen(T)*strlen(T));
  int ss = pm_naive(T, P);
  std::cout<<"from SS="<<ss<<" I found the string:\n";
  
  for (unsigned int i=ss; i<strlen(T);i++){
    std::cout<<*(T+i);
  }
  printf("\n");
  return 0;
}
