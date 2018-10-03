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
  ~adjacency_list(){};

  int return_size() { return size; };
  void print_list();
  node* get_last_node();
  void add_node(int v);
  void add_neighbor(int n, int v);
  bool node_already_present(int i);
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
  printf("ciao\n");
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


void adjacency_list::add_node(int v){
  if (size==0){
    this->root = new node{1,v};
    size++;
    return;
  }
  node* ptr = this-> root;
  while(ptr->next!=nullptr){
    ptr = ptr->next;
  }
  int k = ptr->key;
  k++;
  ptr->next = new node{k,v};
  size++;
}

#endif

/*int main(){

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
  return 0;
}
*/
