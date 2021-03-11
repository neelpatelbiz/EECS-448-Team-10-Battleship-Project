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
  int* moveEasy(Board* p1Board);

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


  /**
   *method used by moveMedium to attack, then if a ship is hit the last_hit array is updated
   *@param Board* p1Board - the player board
   *@param int* pos - the position to attack
   */
  void attackMed(Board* p1Board, int* pos);

  
  /**
   *constructor
   *@param int diff - the difficulty of bot player - 1 is easy, 2 medium, 3 hard
   *@param int numberShips - the number of ships to add to aiBoard
   */
  Ai(int diff, int numberShips);
  ~Ai();
 private:
  //difficulty - 1 - easy 2 - medium 3 - hard
  int diff;
  int numShips;
  Board aiBoard;
  
  int* pos = new int[2];//the next position the ai plays
  int* last_hit = new int[2];//stores the last position that was a hit, and the size of the boat - Initially and after sinking a ship, the array holds [-1,-1]
  
  Board pBoard;
};



#endif
