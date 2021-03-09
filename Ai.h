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
    @param - Board ptr p1board - a copy of the player's board
    @return - the array of ints [row, col] of the move made by ai
   */
  int* move(Board* p1Board);

  /*
    chooses random location to shoot at
    @param - Board ptr p1Board, player's board
    @return - array of ints [row, col] of move made by ai
   */
  int* moveEasy();

   /*
     
    @param - Board ptr p1Board, player's board
    @return - array of ints [row, col] of move made by ai
   */
  int* moveMedium(Board* p1Board);

   /*
    checks every location in player's board, if there is a ship there, that position is returned. Does not update any boards
    @param - Board ptr p1Board, player's board
    @return - array of ints [row, col] of move made by ai
   */
  int* moveHard(Board* p1Board);

  //arguments - difficulty (1-3), numShips
  Ai(int diff, int numberShips);
  ~Ai();
 private:
  //difficulty - 1 - easy 2 - medium 3 - hard
  int diff;
  int numShips;
  Board aiBoard;

  int* pos = new int[2];//the next position the ai plays
  
  Board pBoard;
};



#endif
