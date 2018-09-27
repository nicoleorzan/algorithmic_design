#include <iostream>

//struct node{};

class queue{

  struct node{
    int val;
    node* next;
  };

  node* root;
  // node* last;
  int size;

public:
  queue(){
    size = 0;
    root = nullptr;
  };
  queue(int v) {
    size = 1;
    root = new node{v, nullptr};
  };
  ~queue() {delete root;};
  //~queue();
  
  int return_size() {return size; };
  void print_queue();
  void enqueue(int v);
  void dequeue(int v);
  int dequeue_last();
  int get_head(){return this->root->val;};
  int get_last();
  bool is_empty();

};

bool queue::is_empty(){
  if (size==0) return 1;
  return 0;
}

void queue::print_queue(){
  if (size==0) {
    printf("queue is empty\n");
    return;
  }
  node *ptr = this->root;
  for(int i=0; i<size; i++){
    printf("%i ",ptr->val);
    ptr=ptr->next;
  }
  printf("\n");
}

void queue::enqueue(int v){
  if (size==0){
    this->root = new node{v, nullptr};
    size++;
    return;
  }
  //int i=0;
  //node* last = get_last();
  node *ptr = this->root;
  while(ptr->next!=nullptr){
    ptr=ptr->next;
  }
  ptr->next = new node{v, nullptr};
  size++;
}

void queue::dequeue(int v){
  printf("dequeuing value %i \n", v);
  if (size!=0){
    if (this->root->val == v){
      printf("value is root\n");
      this->root = this->root->next;
      size--;
      return;
      }

    node *ptr = this->root;
    for (int i=1; i<size; i++){
      if (ptr->next->val == v){
	ptr->next=ptr->next->next;
	size--;
	return;
      }
      else{
	ptr=ptr->next;
	//printf("iterating to %i \n", ptr->val);
      } 
    }
  }
}

int queue::get_last(){
  node* ptr = this->root;
  while(ptr->next!=nullptr){
    ptr=ptr->next;
  }
  return ptr->val;
}

int queue::dequeue_last(){
  this->get_last();
}

int main(){


  queue q(2);
  q.enqueue(3);
  q.enqueue(5);
  q.enqueue(6);
  printf("size of q=%i   ", q.return_size());
  q.print_queue();
  q.enqueue(88);
  printf("size of q=%i   ", q.return_size());
  q.print_queue();

  q.dequeue(3);
  printf("size of q=%i   ", q.return_size());
  q.print_queue();
  printf("head=%i \n",q.get_head());
  // printf("last=%i \n",q.get_last());
  queue ed;
  ed.enqueue(18);
  ed.print_queue();
  ed.dequeue(18);
  ed.print_queue();
  

  return 0;
}

