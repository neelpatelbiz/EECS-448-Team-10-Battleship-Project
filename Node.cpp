#include "Node.h"

Node::Node(int row, int col){
  pos = new int[2];
  pos[0] = row;
  pos[1] = col;
  parent = nullptr;
}

Node::~Node(){
  delete[] pos;
}

int* Node::getPos() const{
  return pos;
}

void Node::setParent(Node* parentNode){
  parent = parentNode;
}

Node* Node::getParent() const {
  return parent;
}
