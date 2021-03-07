#ifndef AI_H
#define AI_H
#include <iostream>
#include "Board.h"
#include "Ships.h"
#include <array>
//#include "stdlib.h"

class Ai{
 public:
  /*
    places Shipnum number of ships randomly in the aiBoard
   */
  void placeShips();

  /*
    calls the move function corresponding with the difficulty of the ai
    @param - Board pboard - a copy of the player's board
   */
  int* move();
  int* moveEasy();
  int* moveMedium();
  int* moveHard();
  //arguments - difficulty (1-3), numShips
  Ai(int diff, int numberShips);
  ~Ai();
 private:
  //difficulty - 1 - easy 2 - medium 3 - hard
  int diff;
  int numShips;
  Board aiBoard;

  int* pos = new int[2];//the next position the ai plays
  
  //Board pBoard;
};



#endif
