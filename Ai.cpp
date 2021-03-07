#include "Ai.h"
#include <iostream>
#include <stdlib.h>

Ai::Ai(int difficulty){
  diff = difficulty;
}

Ai::~Ai(){
}

void Ai::placeShips(){
  srand(1);
  int randnum = rand()%10+1;
  aiBoard.addShip(1,1,1,1);
  aiBoard.Display();
}
