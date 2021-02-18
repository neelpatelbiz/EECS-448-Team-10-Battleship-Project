/**
*	@author
*	@date
*	@file
*	@brief
*/
#include "Ships.h"

Ships::Ships()
{

}

Ships::Ships(int s)
{
  destroyed = false;
  size = s;
  ship = new char[size];
  for(int i = 0; i < size; i++)
  {
    ship[i] = '0';
  }
}

Ships::~Ships()
{
  delete [] ship;
}

void Ships::setSize(int s)
{
  size = s;
}

void Ships::hit(int position)
{
  ship[position] = '1';
}

bool Ships::isDestroyed()
{
  int count = 0;
  for(int i = 0; i < size; i++)
  {
    if(ship[i] == '1')
    {
      count++;
    }
  }
  destroyed = (count == size);
  return destroyed;
}

char* Ships::getShip()
{
  return ship;
}
