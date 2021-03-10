/**
*	@author Team 9 and 10
*	@date 3/6/21
*	@file Executive.cpp
*	@brief member methods for game loops and features
*/
#include "Executive.h"
Executive::Executive()
{
	
	numberOfShips=5;
	gameConfigured = false;
	p1shipsSelected = false;
	p2shipsSelected = false;
	p1CanAttack = false;
	p2CanAttack = false;
	p1Board.setPlayer(1);
	p2Board.setPlayer(2);

	shipColors[0] = ship1;
	shipColors[1] = ship2;
	shipColors[2] = ship3;
	shipColors[3] = ship4;
	shipColors[4] = ship5;

	vert = 0;
	row = 0;
	col = 0;

	W=1008;
	H=504;
	inter.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
	//inter.draw_text(0,0,"* Press a RMB to start turn Player:*",white);
	blankGrid.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			blankGrid.draw_rectangle((W/24)*(j+1)+1,(H/12)*(i+2)+1, 
			(W/24)*(j+2)-1, (H/12)*(i+3)-1, defaultTile);
			
			blankGrid.draw_rectangle((W/24)*(j+13)+1,(H/12)*(i+2)+1, 
			(W/24)*(j+14)-1, (H/12)*(i+3)-1, defaultTile);
		}
	}
	background = blankGrid;
	disp.assign(background,"BattleShip",0,false,false);

}

void Executive::run()
{
	disp.move((CImgDisplay::screen_width() - disp.width())/2,(CImgDisplay::screen_height() - disp.height())/2);
	
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ())
	{
		
		
		if(!gameConfigured)
		{
			printMenu();
		}
		if(!p1shipsSelected)
		{
			selectionPhase(p1Board);
		}
		/*if(switchPlayer == true)
		{
			switchScreen();
		}*/
		if(p1shipsSelected && !p2shipsSelected /*&& switchPlayer == false*/)
		{
			selectionPhase(p2Board);
		}
		if(p1CanAttack == true)
		{
			attackPhase(p1Board);
		}
		if(p2CanAttack == true)
		{
			attackPhase(p2Board);
		}
		/*
		if(p1shipsSelected && p2shipsSelected)
		{
			attackPhase()
		}
		*/
	}
	
}

/*void Executive::switchScreen()
{
	disp.display(inter);
	disp.wait();
	if((disp.button()&2))
	{
		cleanUp();
		disp.display(background);
	}
}*/

void Executive::printMenu()
{
	/*if(cimg::dialog("BASIC RULES",
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
  	background, true))std::exit(0);*/
	gameConfigured = true;
}
void Executive::attackPhase(Board& playerBoard)
{
	
	if((((disp.mouse_x())/(W/24)) >= 13 && ((disp.mouse_x())/(W/24)) <=22)
	&& ((disp.mouse_y())/(H/12)) <=11 && ((disp.mouse_y()-4)/(H/12)) >=2
	&& disp.button()&1)
	{
		row = ((disp.mouse_y())/(H/12));
		col = ((disp.mouse_x())/(W/24));
		if(playerBoard.getPlayer() == 1)
		{
			if(p2Board.attack(row-2, col-13) == 6)
			{
				//youwin
			}
			else if(p2Board.attack(row-2, col-13) == 5)
			{
				
			}
			else if(p2Board.attack(row-2, col-13) == 4)
			{
				
			}
			else if(p2Board.attack(row-2, col-13) == 3)
			{
				
			}
			else if(p2Board.attack(row-2, col-13) == 2)
			{
				
			}
			else if(p2Board.attack(row-2, col-13) == 2)
			{
				
			}
			else if(p2Board.attack(row-2, col-13) == 1)
			{
				
			}
			else if(p2Board.attack(row-2, col-13) == -1)
			{
				
				//hit
			}
			// disp.display(inter);
			// //disp.wait();
			
			p1CanAttack = false;
			//disp.wait();
			//disp.wait(1000);
			//disp.wait();
			loadBoard(p2Board);
			disp.display(background);
			p2CanAttack = true;
			
		}
		else if(playerBoard.getPlayer() == 2 )
		{
			if(p1Board.attack(row-2, col-13) == 6)
			{
				//youwin
			}
			else if(p1Board.attack(row-2, col-13) == 5)
			{
			}
			else if(p1Board.attack(row-2, col-13) == 4)
			{
			}
			else if(p1Board.attack(row-2, col-13) == 3)
			{
			}
			else if(p1Board.attack(row-2, col-13) == 2)
			{
			}
			else if(p1Board.attack(row-2, col-13) == 2)
			{
			}
			else if(p1Board.attack(row-2, col-13) == 1)
			{
			}
			else if(p1Board.attack(row-2, col-13) == -1)
			{
				
				//hit
			}
			// disp.display(inter);
			// //disp.wait();
			//if((disp.button()&2))
			//{
				p2CanAttack = false;
				// disp.wait();
				// disp.wait(1000);
				// disp.wait();
				loadBoard(p1Board);
				disp.display(background);
				p1CanAttack = true;
			//}
			
		}
	}
	
}
void Executive::selectionPhase(Board& playerBoard)
{
	//disp.move((CImgDisplay::screen_width() - disp.width())/2,(CImgDisplay::screen_height() - disp.height())/2);
	
	if(numberOfShips > 0)
	{
		row = ((disp.mouse_y())/(H/12));
		col = ((disp.mouse_x())/(W/24));
		infoAdds = background;
		infoAdds.draw_text(0,0,"Player:%d Orientation: %d tile=%d,%d",gridLines,0,1,13,playerBoard.getPlayer(),vert,row,col);
		disp.display(infoAdds);
		if(disp.is_keyARROWUP())vert = 1;
		if(disp.is_keyARROWDOWN())vert = 0;        
		if( ((((disp.mouse_x())/(W/24)) >= 1 && ((disp.mouse_x())/(W/24)) <=10 ) ||
		(((disp.mouse_x())/(W/24)) >= 13 && ((disp.mouse_x())/(W/24)) <=22))
		&& ((disp.mouse_y())/(H/12)) <=11 && ((disp.mouse_y())/(H/12)) >=2
		&& disp.button()&1)
		{
			row = ((disp.mouse_y())/(H/12));
			col = ((disp.mouse_x())/(W/24));
			infoAdds = background;
			infoAdds.draw_text(0,0,"Player:%d Orientation: %d tile=%d,%d",gridLines,0,1,13,playerBoard.getPlayer(),vert,row,col);
			disp.display(infoAdds);
			if(vert == 1)//draw vertically
			{
				if( playerBoard.addShip(row-2,col-1,vert,numberOfShips) ) 
				{ 
					for(int j=0; j<numberOfShips; j++)
						background.draw_rectangle((col*(W/24))+1, (row+j)*(H/12)+1, (col*(W/24))+(W/24)-1, (row+j)*(H/12)+(H/12)-1, shipColors[numberOfShips%5]);
					numberOfShips--;
					//disp.wait();
				}           
			}
			else if(vert == 0)//draw horizontally
			{
				if( playerBoard.addShip(row-2,col-1,vert,numberOfShips) ) 
				{
					for(int j=0; j<numberOfShips; j++)
						background.draw_rectangle((col+j)*(W/24)+1, row*(H/12)+1, (col+j)*(W/24)+(W/24)-1, row*(H/12)+(H/12)-1, shipColors[numberOfShips%5]);
					numberOfShips--;
					//disp.wait();
				}
			}
			infoAdds = background;
			infoAdds.draw_text(0,0,"Player:%d Orientation: %d tile=%d,%d",gridLines,0,1,13,playerBoard.getPlayer(),vert,row,col);
			disp.display(infoAdds);
			
		}
	}
	else
	{
		if(playerBoard.getPlayer() == 1)
		{
			//inter.draw_text(0,0,"* Press RMB to start turn Player 2:*",white);
			disp.display(inter);
			disp.wait();
			if((disp.button()&2))
			{
				//cleanUp();
				numberOfShips = 5;
				p1shipsSelected = true;
				loadBoard(p2Board);
			}
			
		}
		else if(playerBoard.getPlayer() == 2)
		{
			//inter.draw_text(0,0,"* Press RMB to start turn Player 1:*",white);
			disp.display(inter);
			disp.wait();
			if((disp.button()&2))
			{
				//cleanUp();
				numberOfShips = 5;
				p2shipsSelected = true;
				p1CanAttack = true;
				loadBoard(p1Board);
				//disp.display(background);
			}	
		}
		
	}
}

void Executive::loadBoard(const Board& board)
{
	background = blankGrid;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(board.getEntry(i,j) == -2)
			{
				background.draw_rectangle((W/24)*(j+1)+1,(H/12)*(i+2)+1, 
				(W/24)*(j+2)-1, (H/12)*(i+3)-1, yellow);
			}
			else if(board.getEntry(i,j) == -1)
			{
				background.draw_rectangle((W/24)*(j+1)+1,(H/12)*(i+2)+1, 
				(W/24)*(j+2)-1, (H/12)*(i+3)-1, attacked);
			}
			else if(board.getEntry(i,j) > 0)
			{
				background.draw_rectangle((W/24)*(j+1)+1,(H/12)*(i+2)+1, 
				(W/24)*(j+2)-1, (H/12)*(i+3)-1, shipColors[board.getEntry(i,j)%5]);
			}
		}
	}
	disp.display(background);
	/*background = blankGrid;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(board.getEntry(i,j) == -2)
			{
				background.draw_rectangle((W/24)*(j+1)+1,(H/12)*(i+2)+1, 
				(W/24)*(j+2)-1, (H/12)*(i+3)-1, missedAttack);
			}
			else if(board.getEntry(i,j) == -1)
			{
				background.draw_rectangle((W/24)*(j+1)+1,(H/12)*(i+2)+1, 
				(W/24)*(j+2)-1, (H/12)*(i+3)-1, attacked);
			}
			else if(board.getEntry(i,j) > 0)
			{
				background.draw_rectangle((W/24)*(j+1)+1,(H/12)*(i+2)+1, 
				(W/24)*(j+2)-1, (H/12)*(i+3)-1, shipColors[board.getEntry(i,j)%5]);
			}
			
		}
	}
	disp.display(background);
	*/
}
void Executive::cleanUp()
{
	background = blankGrid;
}

void Executive::Game()
{
	
	
	// int numberOfShips = 0;
	// int row;
	// char column;
	// int vert;
	// bool destroyedbeforesub1 = false;
	// bool destroyedbeforesub2 = false;
	// bool destroyedbeforepatrol1 = false;
	// bool destroyedbeforepatrol2 = false;
	// bool destroyedbeforecruiser1 = false;
	// bool destroyedbeforecruiser2 = false;
	// bool destroyedbeforedestroyer1 = false;
	// bool destroyedbeforedestroyer2 = false;
	// bool destroyedbeforebattleship1 = false;
	// bool destroyedbeforebattleship2 = false;
	// bool destroyedbeforecarrier1 = false;
	// bool destroyedbeforecarrier2 = false;

	
	/*
	numberOfShips = cimg::dialog("Number Of Ships","Enter the number of ships you would like to play with, up to a total of 6.", "1", "2","3","4","5","6", background, true) + 1;
	std::cout << "PLAYER 1" << endl;
	for (int i = 0; i < numberOfShips; i++)
	{
		std::cout << "Enter in the position of where you would like to place your 1x" << i + 1 << " ship." << endl;
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
	*/
}


Executive::~Executive()
{

}
