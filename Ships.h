#ifndef SHIPS_H
#define SHIPS_H

#include <iostream>

class Ships
{
public:
  Ships();
  ~Ships();
  void setSize(int s);
  void setShip();
  void hit(int position);
  bool isDestroyed();

private:
  int size;
  int* ship;
  bool destroyed;

};
#endif
