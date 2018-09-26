#include <iostream>
class Tree{

  struct node{
    int id;
    node *next;

  node(int i): id{i} {};
  //void insert_node(int p);
    
  };

  node* root;
  
public:

  Tree();
  Tree(int i): root{new node{i}} {};
  ~Tree() {delete root; };

};

int main(){

  Tree t{1};
  
  return 0;
}
