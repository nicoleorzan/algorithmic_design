#include <stdlib.h>
#include <iterator>


#ifndef HEAP
#define HEAP

struct Exception{};

template<typename T>
class ValueComparator{
 public:
  
  static int cmp(const T&a, const T&b){
    if (a<b) {return -1;}
    if (b<a) {return 1;}
    return 0;
  }
};

template <typename T, template<typename> class Comparator=ValueComparator >
class BinaryHeap{
  
 protected:
  T* container;  //array
  size_t max_size;   //size of the array
  size_t num_of_elements;   //num elem of the array

  static inline size_t right_son(const size_t i){ return 2*(i+1); }
 
  static inline size_t left_son(const size_t i){ return 2*i+1; }

  static inline size_t father(const size_t i){ return (i-1)/2; }

  virtual void swap(const size_t i, const size_t j){
    std::swap(container[i], container[j]);
  }
  
   void heapify(size_t i){
    do{
      size_t min_son_idx = left_son(i);
      if (min_son_idx >= num_of_elements){ return; }
      if (right_son(i) < num_of_elements && Comparator<T>::cmp(container[min_son_idx], container[right_son(i)]) < 0 ){
	min_son_idx=right_son(i);
      }
      if (Comparator<T>::cmp(container[i], container[min_son_idx]) > 0 ){
	swap(i, min_son_idx);
      }
      else {return; }

      i = min_son_idx;
     
    }while(true);
  }
  
  void build_heap(){
    for (size_t i=num_of_elements/2; i>0; --i){
      heapify(i);
    }
    if(num_of_elements>0) heapify(0);
  }

  
  void fix_heap(size_t i){
    size_t fi=father(i);
    while(i!=0 && Comparator<T>::cmp(container[i], container[fi])>0){
      swap(container[i], container[fi]);
      i=fi;
      fi=father(i);
    }
  }

  template<template<typename, typename> class C>
    void copy_in_heap(const C<T, std::allocator<T>>& container){
    num_of_elements=0;
    max_size = container.size();
    this->container = new T[max_size];
    for(typename C<T, std::allocator<T>>::const_iterator it=std::cbegin(container); it!=std::cend(container); ++it){
      this->container[num_of_elements++] = *it;
    }
  }

 public:
  template<template<typename, typename> class C>
    BinaryHeap(const C<T, std::allocator<T>>& container){
    copy_in_heap(container);
    build_heap();
  }
  
  BinaryHeap(): container{nullptr}, max_size{0}, num_of_elements{0}{}

  ~BinaryHeap(){
    delete[] container;
  }

  void insert(const T& value){
    container[num_of_elements] = value;
    fix_heap(num_of_elements);
    num_of_elements++;
  }

  const T& root_value() const{
    return container[0];
  }

  void delete_root(){
    swap(0, num_of_elements-1);
    num_of_elements --;
    heapify(0);
  }

  void change_value(size_t i, const T& value){
    if(Comparator<T>::cmp(container[i], value) >0){
      throw Exception{};
    }
    container[i]=value;
    fix_heap(i);
  }
  
};


#endif
