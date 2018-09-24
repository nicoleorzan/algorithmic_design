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

  virtual ~BinaryHeap(){
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

  const T& delete_root(){
    swap(0, num_of_elements-1);
    num_of_elements --;
    heapify(0);
  }

  const T& change_value(size_t i, const T& value){
    if(Comparator<T>::cmp(container[i], value) >0){
      throw Exception{};
    }
    container[i]=value;
    fix_heap(i);
  }

 inline size_t size() const{ return number_of_elements;}
 inline size_t get_maxsize() const { return max_size; }

 const T& operator[] (const size_t& i) const {
   if ( i<size() ) return this->container[i];
   throw std::out_of_bound("..");
 }

 const BinaryHeap<T, Comparator>& operator=(const BinaryHeap<T, Comparator> &orig ){
   delete[] container;
   number_of_elements = orig number_of_elements;
   max_size = orig max_size;
   
   container = new T[max_size];

   for (int i=0; i<max_size, ++i){
     container[i] = orig container[i];
   }
   return *this;
 }

 std::ostream& operator<< (std::ostream & os, const BinaryHeap<T, Comparator>& H){
   os<<"BinaryHeap[";
   if( H.size()>0 ){
     os<<H[0];
   }
   for (size_t i=0; i<H.size(); ++i){
     os<<", "<<H[i];
   }
   os<<"]";
 }

 template<T, template<typename, typename> class C>
 C<T,std::allocator<T>> HeapSort(C<T, sdt::allocator<T>>& cont){ //tot compl O(n*log(n))
   BinaryHeap<T, ReverseValueCompatator> H(cont); //O(n)
   while (H.size()>0){
     cont[H.size()] = H.delete_root(); //I keep removing the greatest elem of the BH
   }
   return cont;
 }
 
};

template <typename T, template<typename> class Comparator=ValueComparator >
  class AssociativeBinaryHeap public BinaryHeap<T, Comparator>{
  
 protected:
 size_t *map;

 void swap(const size_t a, const size_t b) override{
   BinaryHeap<T, Comparator>::swap(a,b);
   std::swap(map[a], map[b]);
 }
  
 public:
 
 template< template <typename, typename> class C>
 AssociativeBianryHeap( const C<T, std::allocator<T>>& Cont):  BinaryHeap<T, Comparator>(), map(NULL){
   fill_heap(Cont);
   map = new size_t[max_size];
   for ( size_t i=0; i<max_size; i++){
     map[i]=i;
   }
   build_heap();   
 }

 void insert(const T& value){
   //check size
   map[num_of_elements] = num_of_elements;
   // BinaryHeap<T, Container>::insert(value); cant do this: use wrong swap method
   size_t i = num_of_elements;
   container[i] = valuel;
   fix_heap(i);
 }
 
 const size_t& index(const size_t Graph_node) const{
   //check size
   return map[Graph_node];
 }

 

};


#endif
