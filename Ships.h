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
  void hit(int position);
  bool isDestroyed();
  char* getShip();

private:
  int size;
  char* ship;
  bool destroyed;

};
#endif
