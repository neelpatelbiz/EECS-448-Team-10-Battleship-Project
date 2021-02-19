#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "Ships.h"
using namespace std;
/**
 * draw the borad. deter the ship statues
 * @author  Team 10
 * @version 19, Feb 2021
 */

class Board
{
public:
  /**
	 * store the element
	 * @param   grid it is array to store the syboml
	 */
  Board();
  /**
* discontructor. delete array
* @param   grid array to delete.
*/
  ~Board();
  /**
* show the element in the array
* @param   grid array to show syboml
*/
  void Display();
  /**
* clean the screen. fill out with space
* @param n
*/
  void clearScreen();
  /**
* it is action to chekc how to add ship in the borad
* @param row, column, v, size, type.
*/
  bool addShip(int, int, int, int, int);
  /**
* check the hit of ship , and return it back
* @param row, column is from last function
*/
  string checkHit(int, int);
  /**
*  update ship action
* @param u it is string which contain element.
*/
  void update(int, int, string);

private:
  string** grid;
  int size;

};
#endif
