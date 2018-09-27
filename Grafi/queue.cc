#include <iostream>

//struct node;

class queue{

   struct node{
     int val;
     int key;
     node* next;
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
    root = new node{v, 1, nullptr};
  };
  ~queue() {delete root;};
  
  int return_size() { return size; };
  void print_queue();
  void enqueue(int v);
  void dequeue(int k);
  int dequeue_last();
  int get_head(){return this->root->val;};
  node* get_last();
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
    printf("key=%i, val=%i   \n",ptr->key,ptr->val);
    ptr=ptr->next;
  }
  printf("\n");
}

void queue::enqueue(int v){
  if (size==0){
    this->root = new node{v, 1, nullptr};
    size++;
    return;
  }
  node *ptr = this->root;
  while(ptr->next!=nullptr){
    ptr=ptr->next;
  }
  int k = ptr->key;
  k++;
  ptr->next = new node{v, k, nullptr};
  size++;
}

void queue::dequeue(int k){
  if (k>size){
    printf("key out of size, returning...\n");
    return;
  }
  printf("dequeuing node with key %i \n", k);
  if (size!=0){
    if (this->root->key == k){
      printf("value is root\n");
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
    printf("found\n");
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

int queue::dequeue_last(){
  node* ptr = get_last();
  return ptr->key;
}

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
  ed.dequeue(4);
  ed.print_queue();
  printf("last_key=%i, last_val=%i \n",ed.get_last()->key, ed.get_last()->val);;
  

  return 0;
}

