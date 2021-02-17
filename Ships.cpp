/**
*	@author
*	@date
*	@file
*	@brief
*/
#include "Ships.h"

Ships::Ships()
{
  destroyed = false;
}

Ships::~Ships()
{
  delete [] ship;
}

void Ships::setSize(int s)
{
  size = s;
}

void Ships::setShip()
{
  ship = new int[size];
  for(int i = 0; i < size; i++)
  {
    ship[i] = 0;
  }
}

void Ships::hit(int position)
{
  ship[position] = 1;
}
