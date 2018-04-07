#include <stdlib.h>
#include <iostream>
#include <memory>


enum color { white, grey, black };

class Graph{


  // class Edges{};
  
  class Node{

  public:
    color col;
    int distance;
    std::unique_ptr<Node> parent;
    //constructor without parent
    Node(color c, int d): col{c}, distance{d}, parent{nullptr} {}
    //constructor with parent
    Node(color c, int d, Node* p): col{c}, distance{d}, parent{p} {}
    
  };


  class Edges{
    
  public:
    std::unique_ptr<Node> from;
    std::unique_ptr<Node> to;
    int weight;
  };

  std::unique_ptr<Node> head;
  
public:
  Graph(color c): head{new Node{c, 0}} {}

  ~Graph();
};



  

  int main(){




    
    
    return 0;

  }
