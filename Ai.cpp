#include "Ai.h"
#include <iostream>
#include <stdlib.h>

Ai::Ai(int difficulty, int numberShips){
  diff = difficulty;
  numShips = numberShips;
  pos[0] = 0;
  pos[1] = 0;
  last_hit[0] = -1;
  last_hit[1] = -1;
}

Ai::~Ai(){
  delete[] pos;
  delete[] last_hit;
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


int* Ai::move(Board* p1Board){
  switch(diff){
  case 1:
    pos = moveEasy(p1Board);
    break;
  case 2:
    pos = moveMedium(p1Board);
    break;
  case 3:
    pos = moveHard(p1Board);
    break;
  }
  return pos;
}


int* Ai::moveEasy(Board* p1Board){
  pos[0] = rand()%10;
  pos[1] = rand()%10;
  p1Board->attack(pos[0], pos[1]);
  return pos;
}


int* Ai::moveMedium(Board* p1Board){
  //if lastpos == -1,-1
  //random
  //else
  //check entry of up right down left
  //if not attacked or sunk attack, then if result is hit make lastpos the hit
  //

  if(last_hit[0]==-1 && last_hit[1]==-1){
    pos[0] = rand()%10;
    pos[1] = rand()%10;
    attackMed(p1Board, pos);
  }else{
    //up
    pos[0] = last_hit[0]-1;
    if(pos[0]>=0){
      if(p1Board->getEntry(pos[0], pos[1])>=0){
	attackMed(p1Board, pos);
	return pos;
      }
    }
    //right
    pos[1] = last_hit[1]+1;
    if(pos[1]<10){
      if(p1Board->getEntry(pos[0], pos[1])>=0){
	attackMed(p1Board, pos);
	return pos;
      }
    }
    //down
    pos[0] = last_hit[0]+1;
    if(pos[0]<10){
      if(p1Board->getEntry(pos[0], pos[1])>=0){
	attackMed(p1Board, pos);
	return pos;
      }
    }
    //left
    pos[1] = last_hit[1]-1;
    if(pos[1]>=0){
      if(p1Board->getEntry(pos[0], pos[1])>=0){
	attackMed(p1Board, pos);
	return pos;
      }
    }
    
    //if no empy spaces
    last_hit[0] = -1;
    last_hit[1] = -1;
  }
  return pos;
}

void Ai::attackMed(Board* p1Board, int* pos){
  int result = p1Board->attack(pos[0], pos[1]);
  if(result == -1){
    last_hit[0] = pos[0];
    last_hit[1] = pos[1];
  }
}

 
int* Ai::moveHard(Board* p1Board){
  for(int i = 0; i < 10; i ++){
    for(int j = 0; j < 10; j ++){
      if(p1Board->getEntry(i,j)>0){
	pos[0] = i; pos[1] = j;
      }
    }
  }
  p1Board->attack(pos[0], pos[1]);
  return pos;
}
