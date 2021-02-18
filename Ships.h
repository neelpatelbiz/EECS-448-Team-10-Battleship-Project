#ifndef SHIPS_H
#define SHIPS_H

#include <iostream>
#include <string>

class Ships
{
public:
  Ships();
  ~Ships();
  void setSize(int s);
  void setShip();
  void hit(string position);
  bool isDestroyed();

private:
  int size;
  char* ship;
  bool destroyed;

};
#endif
