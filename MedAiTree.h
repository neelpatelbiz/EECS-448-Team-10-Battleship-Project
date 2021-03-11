#ifndef MEDAITREE_H
#define MEDAITREE_H

#include "Node.h"
#include "Board.h"

class MedAiTree{
 public:
  MedAiTree(Board* pBoard, int row, int col);
  ~MedAiTree();
 private:
  Node* current;
  Board* pBoard;
  
  void move();
};
#endif
