#include "Board.h"
using namespace std;
Board::Board()
{
  size = 11;
  grid = new std::string*[size];

  for (int i = 0; i < size; i++)
  {
    grid[i] = new std::string[size];
  }

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (i == 0)
      {
  //	Convert to ASCII For Loop
        grid[i][0] = '|';
        grid[i][1] = " A";
        grid[i][2] = "B";
        grid[i][3] = "C";
        grid[i][4] = "D";
        grid[i][5] = "E";
        grid[i][6] = "F";
        grid[i][7] = "G";
        grid[i][8] = "H";
        grid[i][9] = "I";
        grid[i][10] = "J";
       }
       else if (j == 0)
       {
        grid[1][j] = "1 ";
        grid[2][j] = "2 ";
        grid[3][j] = "3 ";
        grid[4][j] = "4 ";
        grid[5][j] = "5 ";
        grid[6][j] = "6 ";
        grid[7][j] = "7 ";
        grid[8][j] = "8 ";
        grid[9][j] = "9 ";
        grid[10][j] = "10";
       }
       else
       {
        grid[i][j] = '.';
       }
     }
   }
}

Board::~Board()
{
  for (int i = 0; i < size; i++)
  {
 	  delete[] grid[i];
  }
    delete[] grid;
}

void Board::Display()
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

void Board::clearScreen()
{
  for(int i = 0; i < 70; i++)
  {
    cout << endl;
  }
}

bool Board::addShip(int row, int column, int v, int size)
{
  bool added = false;
    bool tested = true;
    int testRow = row;
    int testColumn = column;
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
                if (grid[testRow][column] == "0")
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
                grid[row][column] = "0";
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
                if (grid[row][testColumn] == "0")
                {
                    tested == false;
                }
                testColumn++;
            }
        }
        if (tested == true)
        {
            for (int i = 0; i < size; i++)
            {
                grid[row][column] = "0";
                column++;
            }
            added = true;
        }
    }
    return added;
}
