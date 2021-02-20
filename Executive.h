#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "Board.h"
#include "Ships.h"

class Executive
{
public:
    void run();
    Executive();
    ~Executive();

private:
    void PrintMenu();
    void Game();
  	Board p1HitOrMiss;
	  Board p1Ships;
	  Board p2HitOrMiss;
	  Board p2Ships;

	  Ships p1Carrier;
	  Ships p2Carrier;
	  Ships p1BattleShip;
	  Ships p2BattleShip;
	  Ships p1Destroyer;
	  Ships p2Destroyer;
	  Ships p1Cruiser;
	  Ships p2Cruiser;
	  Ships p1Patrol;
	  Ships p2Patrol;
	  Ships p1Sub;
	  Ships p2Sub;
};
#endif
