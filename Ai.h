#ifndef AI_H
#define AI_H
#include <iostream>
#include "Board.h"
#include "Ships.h"
//#include "stdlib.h"

class Ai{
 public:
  void placeShips();

  //arguments - difficulty (1-3), numShips
  Ai(int diff, int numberShips);
  ~Ai();
 private:
  //difficulty - 1 - easy 2 - medium 3 - hard
  int diff;
  int numShips;
  Board aiBoard;
  Board pBoard;
};



#endif
