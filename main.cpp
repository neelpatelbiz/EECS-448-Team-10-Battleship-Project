/**
*	@author
*	@date
*	@file
*	@brief
*/
#include <iostream>
#include "Excutive.h"
using namespace std;
int main()
{
	//Executive exe();
	//exe.run();
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
	switch(numberOfShips)
	{
		case 6:
			Ship p1Carrier(6);
			Ship p2Carrier(6);
		case 5:
			Ship p1BattleShip(5);
			Ship p2BattleShip(5);
		case 4:
			Ship p1Destroyer(4);
			Ship p2Destroyer(4);
		case 3:
			Ship p1Cruiser(3);
			Ship p2Cruiser(3);
		case 2:
			Ship p1Patrol(2);
			Ship p2Patrol(2);
		default:
			Ship p1Sub(1);
			Ship p2Sub(1);

	}
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

 //SAMPLE PROMPTS: ALL OF THESE NEED TO BE CODED INTO THEIR RESPECITVE SPOTS
	//ADD code to make actually affect board.
	cout << "Great, both players' boats have now been placed on the board. Now, it is time to attack the enemy!";
	cout << endl;
	cout << endl;
	int turn = 1;

	//Turn Text with turn counter
	cout << "PLAYER 1 TURN [" << turn << "]";
	cout << endl;
	//stuff happens
	cout << "PLAYER 2 TURN [" << turn << "]";
	cout << endl;

 //Player ship sunk
	cout << "YOUR " <<  "insert ship name" << " SUNK!";
	cout << endl;

//Player ship hit
	cout << "YOUR " << "insert ship name" << " WAS HIT!";
  cout << endl;

//Enemy ship hit
	cout << "HIT!";
  cout << endl;

//Enemy ship miss
cout << "MISS!";
cout << endl;


//Enemy ship sunk
cout << "YOU SUNK A " << "insert ship name" <<"!";
cout << endl;

 cout << "PLAYER 1 LOST!";
 cout << endl;

 cout << "PLAYER 2 LOST!";
 cout << endl;

 cout << "PLAYER 1 WON!";
 cout << endl;

 cout << "PLAYER 2 WON!";
 cout << endl;
}
