#ifndef NODE_H
#define NODE_H
class Node{
 public:
  Node(int row, int col);
  ~Node();
  int* getPos() const;
  void setParent(Node* parentNode);
  Node* getParent() const;
  
 private:
  int* pos;
  Node* parent;
  
};
#endif
