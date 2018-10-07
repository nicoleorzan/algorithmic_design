#include <stdlib.h>
#include <iostream>
#include "binaryheap.h"
#include <vector>

#ifndef BINH
#define BINH

template<typename T>
class compar{
  
 public:
  static int cmp(const T&a, const T&b){
    if (a<b) {return -1;}
    if (b<a) {return 1;}
    return 0;
  }
};

#endif


int main(){

  std::vector<int> v{4,2,6,1,3,5,7};

  std::cout<<"inserting:"<<std::endl;
  for(unsigned int j=0; j< v.size(); j++){
    std::cout<<v[j]<<" ";
  }
  std::cout<<std::endl;
  BinaryHeap<int, compar> heap{v};

  int pr=8;
  std::cout<<"inserting "<<pr<<std::endl;
  heap.insert(pr);

  heap.delete_root();
  
  return 0;  
  }
