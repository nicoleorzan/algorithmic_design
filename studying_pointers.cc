#include <stdio.h>
#include <stdlib.h>

int main(){

  int a = 6;
  int* pt = &a;
  printf("a = %i \n",a);
  printf("&a = %p \n",&a);
  printf("pt = %p \n",pt);
  printf("*pt = %i \n",*pt);

  printf("sizeof(*pt) =  %lu\n", sizeof(*pt));
 
return 0;
}
