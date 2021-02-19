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
  bool addShip(int, int, int, int, int);
  string checkHit(int, int);
  void update(int, int, string);

private:
  string** grid;
  int size;

};
#endif
