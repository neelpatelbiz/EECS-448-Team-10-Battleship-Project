#include <iostream>
#include "Executive.h"
#include "Board.h"
#include "Ships.h"
#include "Ai.h"
#include <array>

using namespace std;
int main()
{
  //Executive exe;
	//exe.run();
  Ai ai1(1, 7);
  ai1.placeShips();
  Board pBoard;
  int* pos = ai1.move(&pBoard);
  std::cout<<pos[0]<<","<<pos[1];
}
