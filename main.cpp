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
	cout << "Enter the number of ships you would like to play with, up to a total of 6." << endl;
	cin >> numberOfShips;
	cout << "HIDE THE SCREEN SO ONLY ONE PLAYER CAN SEE IT" << endl;
	cout << "PLAYER 1" << endl;
	for(int i = 0; i < numberOfShips; i++)
	{
		cout << "Enter in the position of where you would like to place each ship, starting with a 1x1 and ending with a 1x" << numberOfShips << "." << endl;
		cout << "Rows are labeled A-J, and columns are 1-10" << endl;
	}





























	int size = 10;
 char** grid = new char*[size];

 for (int i = 0; i < size; i++)
 {
	 grid[i] = new char[size];
 }

 for (int i = 0; i < size; i++)
 {
	 for (int j = 0; j < size; j++)
	 {
		grid[i][j] = '.';
	 cout << grid[i][j] << " ";
	 }
	 cout << std::endl;
 }

 for (int i = 0; i < size; i++)
 {
	delete[] grid[i];
 }
	delete[] grid;
}

	return (0);

}
