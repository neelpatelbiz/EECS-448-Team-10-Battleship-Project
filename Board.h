#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "Ships.h"
using namespace std;

class Board
{
public:
  Board();
  ~Board();
  void Display();
  void clearScreen();
  void addShip(int, int, int, int);


private:
  string** grid;
  int size;

};
#endif
