#include "Board.h"
#include "CImg.h"

Board::Board()
{
  //W=500;
  //H=500;
  score = 0;
  size = 10;
  hitsToWin=0;
  shipGrid = new int*[size];
  attackGrid = new int*[size];

  for (int i = 0; i < size; i++)
  {
    shipGrid[i] = new int[size];
    attackGrid[i] = new int[size];
  }

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      shipGrid[i][j] = 0;
      attackGrid[i][j] = 0;  
    }
  }
  for(int i =1; i<=5; i++)
  {
    piecesLeft[i-1]=i;
  }
}

Board::~Board()
{
  for (int i = 0; i < size; i++)
  {
 	delete[] shipGrid[i];
    delete[] attackGrid[i];
  }
  delete[] shipGrid;
  delete[] attackGrid;
}

bool Board::addShip(int row, int column, int v, int size)
{
  bool canAdd = true;
  if(v == 1)
  {
    if ((size + row) > 10)
    {
      return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (shipGrid[row+i][column] != 0)
        {
          canAdd = false;
        }
    }
    if (canAdd == true)
    {
        for (int i = 0; i < size; i++)
        {
          shipGrid[row+i][column] = size;
          hitsToWin++;
        }
    }
  }
  else if (v == 0)
  {
    if ((size + column) > 10)
    {
        canAdd = false;
    }
    for (int i = 0; i < size; i++)
    {
        if (shipGrid[row][column+i] != 0)
        {
          canAdd = false;
        }
    }
    if (canAdd == true)
    {
        for (int i = 0; i < size; i++)
        {
          shipGrid[row][column+i] = size;
          hitsToWin++;
        }
    }
  }
  return canAdd;
}

int Board::attack(int row, int col)
{
  int shipSpace = shipGrid[row][col];
  if(shipSpace == -2 || shipSpace == -1) {
    return -2;
  }
  else if(shipSpace == 0) {
    shipGrid[row][col] = -2;
    return 0;
  } 
  else if(piecesLeft[shipSpace-1]-1 == 0) {
    piecesLeft[shipSpace-1]--;
    shipGrid[row][col] = -1;
    hitsToWin--;
    if(hitsToWin == 0)return 6;
      else return shipSpace;
  }
  else {
    piecesLeft[shipSpace-1]--;
    hitsToWin--;
    shipGrid[row][col] = -1;
    return -1;
  }
}

int Board::getEntry(int row, int col)const
{
  return(shipGrid[row][col]);
}

int Board::getPlayer()const
{
  return playerNum;
}

void Board::setPlayer(int num)
{
  playerNum = num;
}

int Board::getScore()
{
  return score;
}

void Board::incScore()
{
  score++;
}

/*void Board::update(int row, int column, char u)
{
    grid[row][column] = u;
}*/
