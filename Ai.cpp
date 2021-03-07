#include "Ai.h"
#include <iostream>
#include <stdlib.h>

Ai::Ai(int difficulty, int numberShips){
  diff = difficulty;
  numShips = numberShips;
  pos[0] = 0;
  pos[1] = 0;
}

Ai::~Ai(){
  delete[] pos;
}

void Ai::placeShips(){
  srand(3);
  for(int s = 1; s <= numShips; s ++){

    int i  = rand()%10;
    int j = rand()%10;
    int v = rand()%2;
    
    if(aiBoard.addShip(i,j,v,s)==false){
      s--;
    }
  }
  aiBoard.Display();
}


int* Ai::move(){
  switch(diff){
  case 1:
    pos = moveEasy();
    std::cout<<pos[0];
    break;
  case 2:
    pos = moveMedium();
    break;
  case 3:
    pos = moveHard();
    break;
  }
  return pos;
}


int* Ai::moveEasy(){
  pos[0] = rand()%10;
  pos[1] = rand()%10;
  return pos;
}


int* Ai::moveMedium(){
  return pos;
}

 
int* Ai::moveHard(){
  return pos;
}
