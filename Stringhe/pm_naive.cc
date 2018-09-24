#include <iostream>
#include <cstring>
#include <stdio.h>

int pm_naive(char* T, char* P){

  int i=0;
  int ss;
  int len = strlen(T);
  for (int s = 0 ; s < ( strlen(T) - strlen(P)  ); s++){
    i = 1;
    std::cout<<"s= "<<s<<"\n";
    while (i<=strlen(P) && P[i]==T[s+i]){
      i++;
      std::cout<<"i= "<<i<<"\n";
    }
    if ( i>strlen(P) ) {
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
  int ss = pm_naive(T, P);
  std::cout<<ss<<"\n";
  /* char a[10];
  std::cin>>a;
  std::cout<<a<<"\n";*/
    
  return 0;
}








  /*const char *const pszSource = "This is an example.";
  const char *pszChar = pszSource;

  while (pszChar != NULL && *pszChar != '\0'){
    printf("%s", pszChar);
    ++pszChar;
    }*/
