#ifndef AI_H
#define AI_H
#include <iostream>
#include "Board.h"
#include "Ships.h"
//#include "stdlib.h"

class Ai{
 public:
  void placeShips();

  
  Ai(int diff);
  ~Ai();
 private:
  //difficulty - 1 - easy 2 - medium 3 - hard
  int diff;
  Board aiBoard;
  Board pBoard;
};



#endif
