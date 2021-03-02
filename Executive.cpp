/**
*	@author
*	@date
*	@file
*	@brief
*/
#include "Board.h"
#include "Executive.h"
#include "Ships.h"
#include "CImg.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace cimg_library;
const unsigned int W = 500, H = 500;
CImg<unsigned char> background(W, H, 1, 3, 255); 
//background.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);

Executive::Executive()
{
	p1Carrier.buildShip(6);
	p2Carrier.buildShip(6);
	p1BattleShip.buildShip(5);
	p2BattleShip.buildShip(5);
	p1Destroyer.buildShip(4);
	p2Destroyer.buildShip(4);
	p1Cruiser.buildShip(3);
	p2Cruiser.buildShip(3);
	p1Patrol.buildShip(2);
	p2Patrol.buildShip(2);
	p1Sub.buildShip(1);
	p2Sub.buildShip(1);
}

void Executive::run()
{
	PrintMenu();
	Game();
}

void Executive::PrintMenu()
{
	if(cimg::dialog("BASIC RULES",
	"The goal of the game is to eliminate all of your opponent's ships\n"
	"by selecting spots on the game board to see if you hit or miss.\n"
	"The game is over when one player loses all of their ships.\n\n"
	"At the beginning of the game, each player will set up their boats on a 10x10 grid simulating a board.\n"
	"Do NOT HIT the same coordinates more than one time when picking where to hit an enemy boat.\n"
	"You will have the choice between playing with 1 to 6 ships that you will place on the board:\n\n"
	"Games with 1 ship: \nSub: (1x1)\n\n"
	"2 ships: \nSub: (1x1), Patrol Boat: (1x2)\n\n"
	"3 ships: \nSub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3)\n\n"
	"4 ships: \nSub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3), Destroyer: (1x4)\n\n"
	"5 ships: \nSub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3), Destroyer: (1x4), Battleship: (1x5)\n\n"
	"6 ships: \nSub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3), Destroyer: (1x4), Battleship: (1x5), Carrier: (1x6)\n\n",
   	"Start", "Quit",0,0,0,0,
  	background, true))std::exit(0);
}

void Executive::Game()
{
	int numberOfShips = 0;
	int row;
	char column;
	int vert;
	bool destroyedbeforesub1 = false;
	bool destroyedbeforesub2 = false;
	bool destroyedbeforepatrol1 = false;
	bool destroyedbeforepatrol2 = false;
	bool destroyedbeforecruiser1 = false;
	bool destroyedbeforecruiser2 = false;
	bool destroyedbeforedestroyer1 = false;
	bool destroyedbeforedestroyer2 = false;
	bool destroyedbeforebattleship1 = false;
	bool destroyedbeforebattleship2 = false;
	bool destroyedbeforecarrier1 = false;
	bool destroyedbeforecarrier2 = false;


	numberOfShips = cimg::dialog("Number Of Ships","Enter the number of ships you would like to play with, up to a total of 6.", "1", "2","3","4","5","6", background, true) + 1;
	cout << "PLAYER 1" << endl;
	for (int i = 0; i < numberOfShips; i++)
	{
		cout << "Enter in the position of where you would like to place your 1x" << i + 1 << " ship." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> column;
		}
		int trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		cout << "Enter a 1 if you want the ship to be oriented vertically, 0 for horizontal." << endl;
		cin >> vert;
		while (cin.fail() || vert > 1 || vert < 0)
		{
			cout << "Not a valid orientation, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> vert;
		}

		if ((p1Ships.addShip(row, trueColumn, vert, i + 1, i)) == false)
		{
			cout << "SHIP WAS UNABLE TO BE ADDED, TRY AGAIN." << endl;
			i--;
		}
		p1Ships.Display();
		//std::this_thread::sleep_for(7s);
	}
	p1Ships.clearScreen();
	cout << "SWITCH PLAYERS" << endl;
	cout << "PLAYER 2" << endl;
	for (int i = 0; i < numberOfShips; i++)
	{
		cout << "Enter in the position of where you would like to place your 1x" << i + 1 << " ship." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> column;
		}
		int trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		cout << "Enter a 1 if you want the ship to be oriented vertically, 0 for horizontal." << endl;
		cin >> vert;
		while (cin.fail() || vert > 1 || vert < 0)
		{
			cout << "Not a valid orientation, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> vert;
		}
		if ((p2Ships.addShip(row, trueColumn, vert, i + 1, i)) == false)
		{
			cout << "SHIP WAS UNABLE TO BE ADDED, TRY AGAIN." << endl;
			i--;
		}
		p2Ships.Display();
		//std::this_thread::sleep_for(7s);
	}
	p2Ships.clearScreen();
	cout << "Great, both players' boats have now been placed on the board. Now, it is time to attack the enemy!";
	cout << endl << endl;

	bool winner = false;
	int turn = 1;
	int totalDestroyed1 = 0;
	int totalDestroyed2 = 0;

	std::string ready = "";
	do
	{
		cout << "Are you ready to begin the game? (y/n)";
		cout << endl;
		cin >> ready;

	} while (ready != "yes" && ready != "y");

	cout << endl << endl;

	while (winner == false)
	{
		cout << "PLAYER 1 TURN [" << turn << "]";
		cout << endl << endl;

		cout << "YOUR SHIPS:";
		cout << endl << endl;

		p1Ships.Display();

		cout << endl << endl;

		cout << "ENEMY SHIPS:";
		cout << endl << endl;

		p1HitOrMiss.Display();
		cout << endl << endl;
		cout << "Enter in the position of where you would like to attack." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin >> column;
		}
		int trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		string spot = p2Ships.checkHit(row, trueColumn);
		if (spot != ".")
		{
			cout << "HIT!";
			cout << endl;
			if (spot == "S")
			{
				p2Sub.hit();
				if (p2Sub.isDestroyed() == true)
				{
					if (destroyedbeforesub2 == false)
					{
						destroyedbeforesub2 = true;
						totalDestroyed1++;
						cout << "YOU SUNK A SUBMARINE!";
						cout << endl;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}
				}
			}
			if (spot == "P")
			{
				p2Patrol.hit();
				if (p2Patrol.isDestroyed() == true)
				{
					if (destroyedbeforepatrol2 == false)
					{
						destroyedbeforepatrol2 = true;
						totalDestroyed1++;
						cout << "YOU SUNK A PATROL BOAT!";
						cout << endl;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}
				}
			}
			if (spot == "c")
			{
				p2Cruiser.hit();
				if (p2Cruiser.isDestroyed() == true)
				{
					if (destroyedbeforecruiser2 == false)
					{

						totalDestroyed1++;
						cout << "YOU SUNK A CRUISER!";
						cout << endl;
						destroyedbeforecruiser2 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "D")
			{
				p2Destroyer.hit();
				if (p2Destroyer.isDestroyed() == true)
				{
					if (destroyedbeforedestroyer2 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A DESTROYER!";
						cout << endl;
						destroyedbeforedestroyer2 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "B")
			{
				p2BattleShip.hit();
				if (p2BattleShip.isDestroyed() == true)
				{
					if (destroyedbeforebattleship2 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A BATTLESHIP!";
						cout << endl;
						destroyedbeforebattleship2 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}
				}
			}
			if (spot == "C")
			{
				p2Carrier.hit();
				if (p2Carrier.isDestroyed() == true)
				{
					if (destroyedbeforecarrier2 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A CARRIER!";
						cout << endl;
						destroyedbeforecarrier2 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			p1HitOrMiss.update(row, trueColumn, "H");
		}
		else
		{
			cout << "MISS!";
			cout << endl;
			p1HitOrMiss.update(row, trueColumn, "M");
		}

		if (totalDestroyed1 == numberOfShips)
		{
			winner = true;
		}

		cout << "PLAYER 2 TURN [" << turn << "]";
		cout << endl;
		//std::this_thread::sleep_for(7s);

		cout << "YOUR SHIPS:";
		cout << endl << endl;

		p2Ships.Display();

		cout << endl << endl;

		cout << "ENEMY SHIPS:";
		cout << endl << endl;

		p2HitOrMiss.Display();
		cout << endl << endl;
		cout << "Enter in the position of where you would like to attack." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin >> column;
		}
		trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		spot = p1Ships.checkHit(row, trueColumn);
		if (spot != ".")
		{
			cout << "HIT!";
			cout << endl;
			if (spot == "S")
			{
				p1Sub.hit();
				if (p1Sub.isDestroyed() == true)
				{
					if (destroyedbeforesub1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A SUBMARINE!";
						cout << endl;
						destroyedbeforesub1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "P")
			{
				p1Patrol.hit();
				if (p1Patrol.isDestroyed() == true)
				{
					if (destroyedbeforepatrol1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A PATROL BOAT!";
						cout << endl;
						destroyedbeforepatrol1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "c")
			{
				p1Cruiser.hit();
				if (p1Cruiser.isDestroyed() == true)
				{
					if (destroyedbeforecruiser1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A CRUISER!";
						cout << endl;
						destroyedbeforecruiser1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "D")
			{
				p1Destroyer.hit();
				if (p1Destroyer.isDestroyed() == true)
				{
					if (destroyedbeforedestroyer1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A DESTROYER!";
						cout << endl;
						destroyedbeforedestroyer1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "B")
			{
				p1BattleShip.hit();
				if (p1BattleShip.isDestroyed() == true)
				{
					if (destroyedbeforebattleship1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A BATTLESHIP!";
						cout << endl;
						destroyedbeforebattleship1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			if (spot == "C")
			{
				p1Carrier.hit();
				if (p1Carrier.isDestroyed() == true)
				{
					if (destroyedbeforecarrier1 == false)
					{
						totalDestroyed1++;
						cout << "YOU SUNK A CARRIER!";
						cout << endl;
						destroyedbeforecarrier1 = true;
					}
					else
					{
						cout << "YOU HAVE ALREADY HIT THIS SPOT.";
						cout << endl;
					}

				}
			}
			p2HitOrMiss.update(row, trueColumn, "H");
		}
		else
		{
			cout << "MISS!";
			cout << endl;
			p2HitOrMiss.update(row, trueColumn, "M");
		}

		if (totalDestroyed2 == numberOfShips)
		{
			winner = true;
		}
		//std::this_thread::sleep_for(7s);
		turn++;
	}

	if (totalDestroyed1 == numberOfShips)
	{
		cout << "PLAYER 2 LOST!";
		cout << endl;

		cout << "PLAYER 1 WON!";
		cout << endl;
	}
	else
	{
		cout << "PLAYER 1 LOST!";
		cout << endl;

		cout << "PLAYER 2 WON!";
		cout << endl;
	}
}


Executive::~Executive()
{

}
