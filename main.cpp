/**
*	@author
*	@date
*	@file
*	@brief
*/
#include <iostream>
using namespace std;
int main()
{
	bool loop = true;
	int selection = 0;
  cout << "  WELCOME TO" << endl;
  cout << " //BATTLESHIP//" << endl << endl << endl;
  while(loop)
  {
    cout << "Enter in number to navigate menu" << endl;
    cout << "1: Start Game" << endl;
    cout << "2: How to Play" << endl;
    cin >> selection;
    switch (selection)
    {
      case 1:
        loop = false;
        break;
      case 2:
				cout << "BASIC RULES" << endl;
			  cout << "The goal of the game is to eliminate all of your opponent's ships ";
			  cout << "by selecting spots on the game board to see if you hit or miss." << endl;
			  cout << "The game is over when one player loses all of their ships." << endl;
        break;
      default:
      cout << selection << " is not a valid choice, try again." << endl;
    }
  }
	int numberOfShips = 0;
	int row;
	char column;
	cout << "Enter the number of ships you would like to play with, up to a total of 6." << endl;
	cin >> numberOfShips;
	cout << "HIDE THE SCREEN SO ONLY ONE PLAYER CAN SEE IT" << endl;
	cout << "PLAYER 1" << endl;
	for(int i = 0; i < numberOfShips; i++)
	{
		cout << "Enter in the position of where you would like to place each ship, starting with a 1x1 and ending with a 1x" << numberOfShips << "." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while(row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while(column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin >> column;
		}
	}
	cout << "SWITCH PLAYERS" << endl;
	cout << "PLAYER 2" << endl;
	for(int i = 0; i < numberOfShips; i++)
	{
		cout << "Enter in the position of where you would like to place each ship, starting with a 1x1 ship and ending with a 1x" << numberOfShips << "." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while(row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while(column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin >> column;
		}
	}




























	int size = 11;
 char** grid = new char*[size];

 for (int i = 0; i < size; i++)
 {
	 grid[i] = new char[size];
 }

 for (int i = 0; i < size; i++)
 {
	 for (int j = 0; j < size; j++)
	 {
	   if (i == 0)
	   {
//	Add ASCII
		grid[i][0] = '|';
		grid[i][1] = 'A';
		grid[i][2] = 'B';
		grid[i][3] = 'C';
		grid[i][4] = 'D';
		grid[i][5] = 'E';
		grid[i][6] = 'F';
		grid[i][7] = 'G';
		grid[i][8] = 'H';
		grid[i][9] = 'I';
		grid[i][10] = 'J';
	   }
	   else if (j == 0)
	   {
	    grid[1][j] = '1';
	    grid[2][j] = '2';
	    grid[3][j] = '3';
	    grid[4][j] = '4';
	    grid[5][j] = '5';
	    grid[6][j] = '6';
	    grid[7][j] = '7';
	    grid[8][j] = '8';
	    grid[9][j] = '9';
	    grid[10][j] = '0';
	   }
	   else
	   {
		  grid[i][j] = '.';
	   }
	 std::cout << grid[i][j] << " ";
	 }
	 std::cout << std::endl;
	 //ADD in later
// 	 for (int i = 0; i < size; i++)
//  {
// 	delete[] grid[i];
//  }
// 	delete[] grid;
 }
}
