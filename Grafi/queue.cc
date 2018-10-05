#include <iostream>
//#define DEBUG

#ifndef QUEUE
#define QUEUE


class queue{


  
  struct node{

  public:
    int val;
    int key;
    node* next;

    node(int v, int k): val{v}, key{k}, next{nullptr} {}
    node(const node& n):  val{n.val}, key{n.key}, next{n.next} {};
    void copy_node(queue& q){
      if (this->next!=nullptr){
	q.enqueue(next->val);
	this->next->copy_node(q);
      }
    }

  };
  
  node* root;
  int size;

public:
  
  queue(){
    size = 0;
    root = nullptr;
  };
  queue(int v) {
    size = 1;
    root = new node{v, 1};
  };
  //copy constructor
  queue(const queue& q) {
    if (q.size!=0){
      size=1;
      root = new node{q.root->val, 1};
      q.root->copy_node(*this);
    }
  };
  ~queue(){};// {delete root;};
  int operator*() {
    return size;
  }

  
  int return_size() { return size; };
  void print_queue();
  void enqueue(int v);
  void enqueue_queue(queue *q);
  void dequeue(int k);
  int dequeue_last_getting_key();
  int dequeue_last_getting_val();
  int get_from_key(int k);
  int get_head();
  int pop();
  node* get_last();
  node* get_penultimate();
  bool is_empty();


  class Iterator{

  using node = queue::node;
  node* current;

public:
  Iterator(node *ptr): current{ptr} {} //iterator constructor
  
  /** Function to move the iterator to the next node */
  Iterator& operator++() {
    if (current->next!=nullptr){
      current = current->next;
    }
    else current=nullptr;
    return *this;
  }
  /** boolean operator to check equality of nodes*/
  bool operator==(const Iterator& other) {
    return this->current == other.current;
  }
  /** boolean operator to check if two nodes are different*/
  bool operator!=(const Iterator& other) { return !(*this == other); }
    
};//end iterator

  Iterator begin(){
    if (root==nullptr)  return Iterator{nullptr};
    node* ptr = this->root;
    return Iterator{ptr};
  }
  Iterator end(){return Iterator{nullptr}; }
  Iterator find(const int v);

};// end queue


class queue::Iterator queue::find(const int v){
  if (root==nullptr) return Iterator{nullptr};
  node* ptr = this->root;
  while (ptr->val!=v && ptr->next!=nullptr){
    ptr=ptr->next;
  }
  if (ptr->next==nullptr) return nullptr;// Iterator{nullptr};
  else return ptr;// Iterator{ptr};
}

bool queue::is_empty(){
  if (size==0) return 1;
  return 0;
}

struct Empty_queue {};

int queue::get_head(){
  if (is_empty()==0){
    printf("queue not empty\n");
    return this->root->val;
  }
  else throw Empty_queue{};
}
void queue::print_queue(){
  if (size==0) {
    printf("queue is empty\n");
    return;
  }
  node *ptr = this->root;
  for(int i=0; i<size; i++){
    //printf("(key=%i, val=%i) ",ptr->key,ptr->val);
    printf("v=%i ",ptr->val);
    ptr=ptr->next;
  }
  printf("\n");
}

void queue::enqueue_queue(queue *q){
  if (size==0){
    //printf("enqueuing nothing\n");
    this->root=q->root;
    size = q->return_size();
    return;
  }
  node *ptr = this->root;
  while(ptr->next!=nullptr){
    ptr=ptr->next;
  }
  // int k = ptr->key;
  //k++;
  ptr->next = q->root;
  size = size + q->return_size();
  
}

void queue::enqueue(int v){
  //#ifdef DEBUG
  // printf("enqueuing\n");
  //#endif
  // printf("queue size = %i\n", size);
  if (size==0){
    printf("queue size==0\n");
    this->root = new node{v, 1};//, nullptr};
    size++;
    return;
  }
  //printf("queue size!=0\n");
  node *ptr = this->root;
  while(ptr->next!=nullptr){
    ptr=ptr->next;
  }
  int k = ptr->key;
  k++;
  ptr->next = new node{v, k};//, nullptr};
  size++;
}

void queue::dequeue(int k){
  if (k>size){
    printf("key out of size, returning...\n");
    return;
  }
  //printf("dequeuing node with key %i \n", k);
  if (size!=0){
    if (this->root->key == k){
      if (size==1){
	this->root=nullptr;
	size--;
	return;
      }
      //printf("value is root\n");
      this->root->next->key = this->root->key;
      this->root = this->root->next;
      node* ptr = this->root;
      //change all others
      while(ptr->next!=nullptr){
	ptr->next->key--;
	ptr=ptr->next;
      }
      //end
      size--;
      return;
      }

    //value is not the root
    node *ptr = this->root;
    while(ptr->next->key!=k){
      ptr=ptr->next;
    }
    //now we found the key
    //printf("found\n");
    if (ptr->next->next!=nullptr){
      ptr->next=ptr->next->next;
      ptr->next->key--;
      ptr = ptr->next;
      while(ptr->next!=nullptr){
	ptr->next->key--;
	ptr=ptr->next;
      }
    }
    size--;
    
  }
}

queue::node* queue::get_last(){
  node* ptr = this->root;
  while(ptr->next!=nullptr){
    ptr=ptr->next;
  }
  return ptr;
}

queue::node* queue::get_penultimate(){
  node* ptr = this->root;
  while(ptr->next->key!=size){
    ptr=ptr->next;
  }
  return ptr;
}


int queue::dequeue_last_getting_key(){
#ifdef DEBUG
  printf("dequeue last getting key\n");
#endif
   if (size==1){
    int k =this->root->key;
    size--;
    delete this->root;
    return k;
  }
  node* ptr = get_penultimate();
  int k = ptr->next->key;
  ptr->next=nullptr;
  size--;

  return k;
}

int queue::dequeue_last_getting_val(){
#ifdef DEBUG
  printf("dequeue last getting val\n");
#endif
  if (size==1){
    int v =this->root->val;
    size--;
    delete this->root;
    return v;
  }
  node* ptr = get_penultimate();
  int v = ptr->next->val;
  ptr->next=nullptr;
  size--;

  return v;
}

int queue::pop(){
  if (this->is_empty()==1) {
    printf("cannot pop an empty queue\n");
    return 0;
  }
#ifdef DEBUG
  printf("pop queue\n");
#endif
  node* ptr=this->root;
  if (size==1){
    //node* ptr=this->root;
    delete this->root;
    size--;
    return 0;
  }
  this->root=this->root->next;
  this->root->key--;
  ptr=this->root;
  while(ptr->next!=nullptr){
    ptr->next->key--;
    ptr=ptr->next;
  }

  size--;
  //printf("size=%i\n",size);
  //printf("return=%i\n",ptr->val);
  return ptr->val;

}

int queue:: get_from_key(int k){
  if (is_empty()==1) {
    printf("cannot get value of empty queue\n");
  }
  node* ptr = this->root;
  while(ptr->key!=k && ptr->next!=nullptr){
    ptr = ptr->next;
  }
  /* if (ptr->next==nullptr) {
    printf("key not found\n");
    return -1;
    }*/
  return ptr->val;
}

#endif

/*
int main(){


  queue q(2);
  q.enqueue(3);
  q.enqueue(5);
  q.enqueue(6);
  printf("size of q=%i\n", q.return_size());
  q.print_queue();
  q.enqueue(88);
  q.enqueue(0);
  q.enqueue(3);
  q.enqueue(99);
  q.enqueue(6);
  q.enqueue(6);
  printf("size of q=%i\n", q.return_size());
  q.print_queue();

  int deq = 14;
  q.dequeue(deq);
  printf("size of q=%i\n", q.return_size());
  q.print_queue();
  printf("head=%i \n",q.get_head());
  printf("last_key=%i, last_val=%i \n",q.get_last()->key,q.get_last()->val);


  printf("\n\nnew queue\n");
  queue ed;
  ed.enqueue(18);
  //ed.print_queue();
  ed.enqueue(18);
  ed.enqueue(8);
  ed.enqueue(1);
  ed.enqueue(6777);
  ed.print_queue();
  ed.pop();
  ed.print_queue();
  //ed.pop();
  //ed.pop();
  //ed.pop();
  //ed.pop();
  //ed.print_queue();
  //ed.dequeue(4);
  //ed.print_queue();
  //printf("penultimate_key=%i, penultimate_val=%i \n",ed.get_penultimate()->key, ed.get_penultimate()->val);
  int u = ed.dequeue_last_getting_key();
  printf("I got u=%i\n", u);
  ed.print_queue();

  printf("===========testing iterator==========\n");
  queue::Iterator it=ed.begin(), end=ed.end();
  for (int j=0; j<ed.return_size(); j++){
    it = ed.find(j);
    //printf("val = %i\n",it->value);
  }

  printf("\nCOPY TEST\n");
  queue q2 = ed;
  printf("original one: \n");
  ed.print_queue();
  printf("copied one: \n");
  q2.print_queue();
  

  return 0;
}*/


