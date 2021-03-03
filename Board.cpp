#include "Board.h"
#include "CImg.h"

void Board::clearBoard()
{
  playerBackground->assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
  enemyBackground->assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      playerBackground.draw_rectangle((W/12)+(W/12)*j,(H/12)*i+(H/6), 
      (W/12)*j+(W/6), (H/12)*i+((3*H)/12), gridLines, 1, ~0U);

      enemyBackground.draw_rectangle((W/12)+(W/12)*j,(H/12)*i+(H/6), 
      (W/12)*j+(W/6), (H/12)*i+((3*H)/12), gridLines, 1, ~0U);
    }
  }
}

Board::Board()
{
  W=500;
  H=500;
  size = 10;
  shipGrid = new char*[size];
  attackGrid = new char*[size];

  for (int i = 0; i < size; i++)
  {
    shipGrid[i] = new char[size];
    attackGrid[i] = new char[size];
  }

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      shipGrid[i] = new char[size];
      attackGrid[i] = new char[size];  
    }
   
  }

  playerBackground = new CImg<unsigned char>(W, H, 1, 3, 255);
  enemyBackground = new CImg<unsigned char>(W, H, 1, 3, 255);
  backgrounds = new CImgList(playerBackground, enemyBackground, false);

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


bool Board::addShip(int row, int column, int v, int size, int type)
{
  bool added = false;
  bool tested = true;
  int testRow = row;
  int testColumn = column;
  string ship = "0";
  switch (type)
  {
    case 0:
        ship = "S";
        break;
    case 1:
        ship = "P";
        break;
    case 2:
        ship = "c";
        break;
    case 3:
        ship = "D";
        break;
    case 4:
        ship = "B";
        break;
    case 5:
        ship = "C";
        break;

  }
  if(v == 1)
  {
      if ((size + row) > 11)
      {
          tested = false;
      }
      if (tested == true)
      {
          for (int i = 0; i < size; i++)
          {
              if (grid[testRow][column] != ".")
              {
                  tested = false;;
              }
              testRow++;
          }
      }
      if (tested == true)
      {
          for (int i = 0; i < size; i++)
          {
              grid[row][column] = ship;
              row++;
          }
          added = true;
      }
  }
  else
  {
      if ((size + column) > 11)
      {
          tested = false;
      }
      if (tested == true)
      {
          for (int i = 0; i < size; i++)
          {
              if (grid[row][testColumn] != ".")
              {
                  tested = false;
              }
              testColumn++;
          }
      }
      if (tested == true)
      {
          for (int i = 0; i < size; i++)
          {
              grid[row][column] = ship;
              column++;
          }
          added = true;
      }
  }
  return added;
}

char Board::checkHit(int row, int column)
{
    return grid[row][column];
}

void Board::update(int row, int column, char u)
{
    grid[row][column] = u;
}
