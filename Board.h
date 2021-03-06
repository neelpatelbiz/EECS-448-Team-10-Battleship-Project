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
  * attack given coordinate
  * @return -1 if hit, -2 if already attacked, 1-5 representing length of ship sunk, 0 miss, 6 gameWin
  * @param row, row coordinate
  * @param col, column is from last function
  */
  int attack(int row, int col);

  /**
  * return integer representing state of tile on the board
  * @return -1 if hit, -2 if already attacked, 1-5 representing length of ship sunk, 0 miss
  * @param row, row coordinate
  * @param col, column is from last function
  */
  int getEntry(int row, int col)const;

  /**
  *  update ship action
  * @param row, column, u it is string which contains element.
  */
  void update(int, int, char);

  /** 
  * @return int corresponding to the player to whom the board belongs
  */
  int getPlayer()const;

  /** 
  * @param int corresponding to the player to whom the board belongs
  */
  void setPlayer(int num);

  /** 
  * @return int corresponding to the player to whom the board belongs
  */
  int getScore();

  /** 
  * @return int corresponding to the player to whom the board belongs
  */
  void incScore();

  /**
   * Debugging function for printing game Arrays
   */ 
  void printBoard();
  
private:
  int piecesLeft[5];
  int playerNum, score, hitsToWin;
  int** shipGrid;
  int** attackGrid;
  int size;
  
  
  //unsigned int W,H;
  //const unsigned char gridLines[3]={128,200,255} , attacked[3] = {255,0,0};
  // CImg<unsigned char>* playerBackground;
  // CImg<unsigned char>* enemyBackground;
  // CImgList<unsigned char>* backgrounds;
  // CImgDisplay playerWindow

};
#endif
