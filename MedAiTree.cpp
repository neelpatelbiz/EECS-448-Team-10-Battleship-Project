#include "MedAiTree.h"

MedAiTree::MedAiTree(Board* playerBoard, int row, int col){
  current = new Node(row, col);
  pBoard = playerBoard;
}

MedAiTree::~MedAiTree(){
  delete current;
}

void MedAiTree::move(){
  //up right down left
  int* pos = current->getPos();
  int row = pos[0];
  int col = pos[1];
  if(row-1>=0){
    if(pBoard->getEntry(row-1, col)!=-2){
      //attack, if hit, then add new node
    }
  }
}
