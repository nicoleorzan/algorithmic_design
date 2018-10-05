#include "queue.cc"
#ifndef AD_LIST
#define AD_LIST

class adjacency_list{

struct node{
  int key;
  int val;
  queue neighbors;
  node *next;

  //node();
  node(int k, int v): key{k}, val{v}, neighbors(), next{nullptr} {};
  //bnode copy constructor
  node(const node& n): key{n.key}, val{n.val}, neighbors{n.neighbors}, next{n.next} {};
  void copy_node(adjacency_list& a){
    if (this->next!=nullptr){
      a.add_node(next->val);
      this->next->copy_node(a);
    }
  }
};

  node* root;
  int size;

public:

  adjacency_list(){
    size=0;
    //root=nullptr;
  };
  adjacency_list(int v) {
    size = 1;
    root = new node{1, v};
  };
  //copy constructor
  adjacency_list(const adjacency_list& a){
    if (a.size!=0){
      size=1;
      root = new node{1,a.root->val};
      a.root->copy_node(*this);
    }
  }
  ~adjacency_list(){};

  int return_size() { return size; };
  void print_list();
  node* get_last_node();
  void add_node(int v);
  void add_neighbor(int n, int v);
  bool node_already_present(int i);
  bool node_is_present(int v);
  node* get_node(int v);
  node* detach_last();
  void reverse();
  /*adjacency_list& operator->() {
    return *root;
    };*/
  
};

struct Empty_list{};

bool adjacency_list::node_already_present(int i){
  if (size==0){
    printf("cannot check empty list!!!\n");
    return 0;// throw Empty_list{};
  }
  node* p = this->root;
  while(p->val!=i && p->next!=nullptr){
    p = p->next;
  }
  if (p->val==i) return 1;
  return 0;
}

void adjacency_list::print_list(){
  if (size==0){
    printf("cannot print empty list!\n");
    return;
  }
  node* p = this->root;
  while(p->next!=nullptr){
    printf("v=%i, ", p->val);
    p->neighbors.print_queue();
    p=p->next;
  }
  printf("v=%i, ", p->val);
   p->neighbors.print_queue();
}

struct Missing_value{};

void adjacency_list::add_neighbor(int n, int v){
  if (size==0) return;
  node* ptr = this->root;
  while(ptr->val!=n && ptr->next!=nullptr){
    ptr = ptr->next;
  }
  if (ptr->val==n){
    ptr->neighbors.enqueue(v);
  }
  //if (ptr->next!=nullptr) throw Missing_value{};
 
}

adjacency_list::node* adjacency_list::get_last_node(){
  if (size==0) throw Empty_list{};
  node*p = this->root;
  while(p->next!=nullptr){
    p=p->next;
  }
  return p;
}

bool adjacency_list::node_is_present(int v){
  if (size==0) throw Empty_list{};
  node*ptr= this->root;
  if (ptr->val==v) return 1;
  while(ptr->val!=v && ptr->next!=nullptr){
    ptr = ptr->next;
  }
  if (ptr->val==v) return 1;
  else return 0;
}

adjacency_list::node* adjacency_list::get_node(int v){
  if (size==0) throw Empty_list{};
  node*ptr= this->root;
  while(ptr->val!=v && ptr->next!=nullptr){
    ptr = ptr->next;
  }
  //if (ptr->next==nullptr) throw Missing_value{};
  if (ptr->val==v) return ptr;
  return nullptr;
}


void adjacency_list::add_node(int v){
  if (size==0){
    this->root = new node{1,v};
    size++;
    return;
  }
  if (this->node_already_present(v)==1) return;
  node* ptr = this-> root;
  while(ptr->next!=nullptr){
    ptr = ptr->next;
  }
  int k = ptr->key;
  k++;
  ptr->next = new node{k,v};
  size++;
}

adjacency_list::node* adjacency_list::detach_last(){
  if (size==0) return nullptr;
  node *ptr = this->root;
  if (size==1){
    this->root=nullptr;
    size--;
    return ptr;
  }
  while(ptr->next->next!=nullptr){
    ptr = ptr->next;
  }
  node *penultimate = ptr;
  node *last = penultimate->next;
  penultimate->next=nullptr;
  size--;
  return last;
}

void adjacency_list::reverse(){//not working 
  adjacency_list* t = new adjacency_list(*this);
  printf("BEFORE\n");
  this->print_list();

  node* ptr_t = t->detach_last();
  this->root = ptr_t;
  //queue* q_tmp = new queue();
  //queue* qqq = new queue();
  node* ptr = this->root;
  //printf("here\n");
  while(t->size>0){
    //printf("here22\n");
    //qqq = ptr_t->next->neighbors;
    //*qqq =  ptr_t->next->neighbors;
    //printf("got\n");
    //qqq->print_queue();
    /*if (ptr_t->next->neighbors.is_empty()!=1){
      printf("val %i and queue\n", ptr_t->next->val);
      *q_tmp= ptr_t->next->neighbors; 
      //ptr->neighbors = q_tmp;
      }*/
    ptr_t = t->detach_last();
    ptr->next=ptr_t;
    //ptr->next->neighbors = q_tmp;
    
    //printf("ptr val %i\n",ptr_t->val);
    ptr = ptr->next;
  }
  printf("AFTER\n");
  this->print_list();
}

#endif

int main(){

  adjacency_list a;
  a.add_node(2);
  a.add_node(3);
  a.add_node(44);
  a.add_node(8);
  a.add_node(12);
  a.add_node(6);
  a.add_neighbor(44,6);
  a.add_neighbor(44,3);
  a.print_list();
  //queue coda = a.get_node(44)->neighbors;
  //coda.print_queue();
  printf("===========\n");
  a.detach_last();
  a.print_list();
  printf("reversing\n");
  a.reverse();
  return 0;
  }
