/**
*	@author
*	@date
*	@file
*	@brief
*/
#include <iostream>
#include "Executive.h"
#include "Board.h"
#include "Ships.h"
using namespace std;
int main()
{
	//Executive exe();
	//exe.run();
	bool loop = true;
	int selection = 0;
	Board p1HitOrMiss;
	Board p1Ships;
	Board p2HitOrMiss;
	Board p2Ships;
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
	bool vert;
	cout << "Enter the number of ships you would like to play with, up to a total of 6." << endl;
	cin >> numberOfShips;
	Ships p1Carrier(6);
	Ships p2Carrier(6);
	Ships p1BattleShip(5);
	Ships p2BattleShip(5);
	Ships p1Destroyer(4);
	Ships p2Destroyer(4);
	Ships p1Cruiser(3);
	Ships p2Cruiser(3);
	Ships p1Patrol(2);
	Ships p2Patrol(2);
	Ships p1Sub(1);
	Ships p2Sub(1);
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
		int trueColumn = (int)column;
		cout << "Enter any value if you want the ship to be oriented vertically, 0 for horizontal." << endl;
		cin >> vert;
		if(i == 0)
		{
			p1Ships.addShip(p1Sub, row, trueColumn, vert, i + 1);
		}
		else if(i == 1)
		{
			p1Ships.addShip(p1Patrol, row, trueColumn, vert, i + 1);
		}
		else if(i == 2)
		{
			p1Ships.addShip(p1Cruiser, row, trueColumn, vert, i + 1);
		}
		else if(i == 3)
		{
			p1Ships.addShip(p1Destroyer, row, trueColumn, vert, i + 1);
		}
		else if(i == 4)
		{
			p1Ships.addShip(p1BattleShip, row, trueColumn, vert, i + 1);
		}
		else if(i == 5)
		{
			p1Ships.addShip(p1Carrier, row, trueColumn, vert, i + 1);
		}
	}
	p1Ships.Display();
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
		int trueColumn = (int)column;
		cout << "Enter any value if you want the ship to be oriented vertically, 0 for horizontal." << endl;
		cin >> vert;
		if(i == 0)
		{
			p2Ships.addShip(p2Sub, row, trueColumn, vert, i + 1);
		}
		else if(i == 1)
		{
			p2Ships.addShip(p2Patrol, row, trueColumn, vert, i + 1);
		}
		else if(i == 2)
		{
			p2Ships.addShip(p2Cruiser, row, trueColumn, vert, i + 1);
		}
		else if(i == 3)
		{
			p2Ships.addShip(p2Destroyer, row, trueColumn, vert, i + 1);
		}
		else if(i == 4)
		{
			p2Ships.addShip(p2BattleShip, row, trueColumn, vert, i + 1);
		}
		else if(i == 5)
		{
			p2Ships.addShip(p2Carrier, row, trueColumn, vert, i + 1);
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
