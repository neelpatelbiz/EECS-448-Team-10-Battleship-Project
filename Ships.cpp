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

void Ships::buildShip(int s)
{
  destroyed = false;
  size = s;
  hits = 0;
}

Ships::~Ships()
{

}

void Ships::setSize(int s)
{
  size = s;
}

void Ships::hit()
{
    hits++;
}

bool Ships::isDestroyed()
{
    if (hits == size)
    {
        destroyed = true;
    }
  return destroyed;
}
