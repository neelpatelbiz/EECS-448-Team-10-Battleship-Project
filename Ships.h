#ifndef SHIPS_H
#define SHIPS_H

#include <iostream>
#include <string>

class Ships
{
public:
  Ships();
  void buildShip(int);
  ~Ships();
  void setSize(int s);
  void hit();
  bool isDestroyed();

private:
  int size;
  int hits;
  bool destroyed;

};
#endif
