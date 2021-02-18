#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

class Board
{
public:
  Board();
  ~Board();
  void Display();
  void clearScreen();


private:
  string** grid;
  int size;

};
#endif
