#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "Ships.h"
using namespace std;
/**
 * Program to implement the Board.
 * @author  Team 10
 * @version 19, Feb 2021
 */

class Board
{
public:
  /**
	 * store the element
	 * @param  grid array to store instances of Ships
	 */
  Board();
  /**
* destuctor. to delete array
* @param   grid array to delete.
*/
  ~Board();
  /**
* show the element in the array
* @param   array index
*/
  void Display();
  /**
* clean the screen
* @param
*/
  void clearScreen();
  /**
* fucntion to add ship
* @param row, column, v, size, type.
  @return true/false
*/
  bool addShip(int, int, int, int, int);
  /**
* check if the grid index (ordinate position) has a ship object
* @param row, column is from last function
*/
  string checkHit(int, int);
  /**
*  update ship action
* @param row, column, u it is string which contains element.
*/
  void update(int, int, string);

private:
  string** grid;
  int size;

};
#endif
