#include "Ai.h"
#include <iostream>
#include <stdlib.h>

Ai::Ai(int difficulty, int numberShips){
  diff = difficulty;
  numShips = numberShips;
}

Ai::~Ai(){
}

void Ai::placeShips(){
  srand(2);
  for(int s = 1; s <= numShips; s ++){

    int i  = rand()%10;
    int j = rand()%10;
    int v = rand()%2;
    
    aiBoard.Display();
  
    //std::cout<<std::endl;
    
    if(aiBoard.addShip(i,j,v,s)==false){
      s--;
    }
    
    //std::cout<<std::endl<<std::endl;
  }
  aiBoard.Display();
}
