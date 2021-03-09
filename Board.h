#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "Ships.h"
using namespace std;

/**
 * Program to implement the Board with a GUI
 * @author  Team 10 and Team 9
 * @version 3, Mar 2021
 */

class Board
{
public:
  void Display();
  /**
	 * initialize ship and attack arrays
	 * @param  grid array to store instances of Ships
	 */
  Board();

  /**
  * destuctor to delete arrays
  * @param   grid array to delete.
  */
  ~Board();
  
  /**
   * helper function resets CImg's to initial background values with grid lines
   */
  //void clearBoard();

  /**
  * fucntion to add ship
  * @param row, column, v, size, type.
  * @return true/false
  */
  bool addShip(int, int, int, int);

  /**
  * check if the grid index (ordinate position) has a ship object
  * @param row, column is from last function
  */
  char checkHit(int, int);

  /**
  *  update ship action
  * @param row, column, u it is string which contains element.
  */
  void update(int, int, char);

  
private:
  char** shipGrid;
  char** attackGrid;
  int size;
  
  
  //unsigned int W,H;
  //const unsigned char gridLines[3]={128,200,255} , attacked[3] = {255,0,0};
  // CImg<unsigned char>* playerBackground;
  // CImg<unsigned char>* enemyBackground;
  // CImgList<unsigned char>* backgrounds;
  // CImgDisplay playerWindow

};
#endif
