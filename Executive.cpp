/**
*	@author Team 9 and 10
*	@date 3/6/21
*	@file Executive.cpp
*	@brief member methods for game loops and features
*/
#include "Executive.h"
Executive::Executive()
{
	gameTypeChosen = false;
	gameConfigured = false;
	difficultyChosen = false;
	p1shipsSelected = false;
	p2shipsSelected = false;
	p1CanAttack = false;
	p2CanAttack = false;
	attackComplete = false;
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
	shipNumSelect.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
	botDifficultySelect.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
	gameTypeSelect.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
	blank.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
	inter.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
	youWin.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
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
	for(int i=0; i<5; i++)
	{
		shipNumSelect.draw_rectangle( (W/5)*i+1, 1, (W/5)*(i+1)-1, H-1, shipColors[i]);
		shipNumSelect.draw_text((W/5)*i+(W/10), H/2-4, "%d ship(s)",white, 0, 1, 13, i+1);
	}
	for(int i=0; i<2; i++)
	{
		gameTypeSelect.draw_rectangle( (W/2)*i+1, 1, (W/2)*(i+1)-1, H-1, shipColors[i]);
		if(i==0)gameTypeSelect.draw_text((W/2)*i+(W/4), H/2-4, "Local Game",white, 0, 1, 13);
		if(i==1)gameTypeSelect.draw_text((W/2)*i+(W/4), H/2-4, "Bot Game",white, 0, 1, 13);
	}
	for(int i=0; i<3; i++)
	{
		botDifficultySelect.draw_rectangle( (W/3)*i+1, 1, (W/3)*(i+1)-1, H-1, shipColors[i]);
		if(i==0)botDifficultySelect.draw_text((W/3)*i+(W/6), H/2-4, "Easy",white, 0, 1, 13);
		if(i==1)botDifficultySelect.draw_text((W/3)*i+(W/6), H/2-4, "Medium",white, 0, 1, 13);
		if(i==2)botDifficultySelect.draw_text((W/3)*i+(W/6), H/2-4, "Hard",white, 0, 1, 13);
	}
	background = blankGrid;
	disp.assign(background,"BattleShip",0,false,false);

}

void Executive::run()
{
	disp.move((CImgDisplay::screen_width() - disp.width())/2,(CImgDisplay::screen_height() - disp.height())/2);
	
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ())
	{
		
		if(!gameTypeChosen)
		{
			gameType();
		}
		else
		{
			if(botGame)
			{
				if(!gameConfigured)
				{
					printMenu();
				}
				if(gameConfigured && !difficultyChosen)
				{
					botDifficulty();
				}
				if(difficultyChosen&&!p1shipsSelected)
				{
					selectionPhase(p1Board);
				}
				if(p1CanAttack == true)
				{
					attackPhase(p1Board);
				}
				
			}
			else
			{
				if(!gameConfigured)
				{
					printMenu();
				}
				if(gameConfigured&&!p1shipsSelected)
				{
					selectionPhase(p1Board);
				}
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
			}
		}
		
	}
	
}

void Executive::botDifficulty()
{
	disp.display(botDifficultySelect);
	disp.wait();
	if(disp.button()&1)
	{
		difficulty = (disp.mouse_x()/(W/3))+1;
		gameTypeSelect.draw_text(W/2-8, 4, "Difficulty Selected!",white, 0, 1, 13, numberOfShipsChoice);
		difficultyChosen = true;
		disp.display(botDifficultySelect);
		disp.wait(1000);
		disp.flush();
	}

}
void Executive::gameType()
{
	disp.display(gameTypeSelect);
	disp.wait();
	if(disp.button()&1)
	{
		botGame = (disp.mouse_x()/(W/2));
		gameTypeSelect.draw_text(W/2-8, 4, "Game Type Selected!",white, 0, 1, 13, numberOfShipsChoice);
		gameTypeChosen = true;
		disp.display(gameTypeSelect);
		disp.wait(1000);
		disp.flush();
	}
}
void Executive::printMenu()
{
	//disp.flush();
	disp.display(shipNumSelect);
	disp.wait();
	if(disp.button()&1)
	{
		numberOfShipsChoice = (disp.mouse_x()/(W/5))+1;
		numberOfShips = numberOfShipsChoice;
		if(botGame)
		{
			bot.placeShips(numberOfShipsChoice, p2Board);
		}
		shipNumSelect.draw_text(W/2-8, 4, "%d ship(s) selected",white, 0, 1, 13, numberOfShipsChoice);
		disp.display(shipNumSelect);
		disp.wait(1000);
		disp.flush();
		gameConfigured = true;
	}
	
}
void Executive::attackPhase(Board& playerBoard)
{
	if(!attackComplete)
	{
		if((((disp.mouse_x())/(W/24)) >= 13 && ((disp.mouse_x())/(W/24)) <=22)
		&& ((disp.mouse_y())/(H/12)) <=11 && ((disp.mouse_y()-4)/(H/12)) >=2
		&& disp.button()&1)
		{
			row = ((disp.mouse_y())/(H/12));
			col = ((disp.mouse_x())/(W/24));
			
			if(playerBoard.getPlayer() == 1)
			{
				attackStatus = p2Board.attack(row-2, col-13);
				switch(attackStatus)
				{
					case(6):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						youWin.draw_text(W/2-8, H/2-4, "YOU WIN P1", white, 0, 33);
						disp.display(youWin);
						p1CanAttack = false;
						break;
					case(5):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 5!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(4):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 4!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(3):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 3!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(2):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 2!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(1):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 1!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(0):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, yellow);
						background.draw_text(W/2-8, H/2-4, "Miss :(", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(-1):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Hit ;)!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					default:
						break;
				}
			}
			else if(playerBoard.getPlayer() == 2 )
			{
				attackStatus = p1Board.attack(row-2, col-13);
				switch(attackStatus)
				{
					case(6):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						youWin.draw_text(W/2-8, H/2-4, "YOU WIN P2", white, 0, 33);
						disp.display(youWin);
						p2CanAttack = false;
						break;
					case(5):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 5!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(4):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 4!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(3):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 3!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(2):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 2!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(1):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Sunk 1!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(0):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, yellow);
						background.draw_text(W/2-8, H/2-4, "Miss :(", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					case(-1):
						background.draw_rectangle((W/24)*col+1,(H/12)*row+1, 
						(W/24)*(col+1)-1, (H/12)*(row+1)-1, attacked);
						background.draw_text(W/2-8, H/2-4, "Hit ;)!", white, 0, 33);
						disp.display(background);
						disp.wait(2000);
						disp.flush();
						attackComplete = true;
						break;
					default:
						break;
				}
				
			}
		}
	}
	else
	{

		if(playerBoard.getPlayer() == 1)
		{
			if(botGame)
			{
				loadBoard(p1Board);
				background.draw_text(W/2-30, H/2-4, "Bot is attacking", white, 0, 33);
				disp.display(background);
				disp.wait(1000);
				disp.flush();

				if(bot.botAttack(difficulty,p1Board))
				{
					loadBoard(p1Board);
					disp.wait(1000);
					disp.flush();
					p1CanAttack = false;
					youWin.draw_text(W/2-8, H/2-4, "BOT HAS WON", white, 0, 33);
					disp.display(youWin);
				}
				else
				{
					loadBoard(p1Board);
					attackComplete = false;
				}
			}
			else
			{
				inter.draw_text(W/2-30, H/2-4, "Right Click To Begin Turn P2", white, 0, 33);
				disp.display(inter);
				disp.wait();
				if((disp.button()&2))
				{
					p1CanAttack = false;
					loadBoard(p2Board);
					disp.display(background);
					p2CanAttack = true;
					attackComplete = false;
					disp.flush();
					inter = blank;
				}
			}
		}
		else if(playerBoard.getPlayer() == 2)
		{
			inter.draw_text(W/2-30, H/2-4, "Right Click To Begin Turn P2", white, 0, 33);
			disp.display(inter);
			disp.wait();
			if((disp.button()&2))
			{
				p2CanAttack = false;
				loadBoard(p1Board);
				disp.display(background);
				p1CanAttack = true;
				attackComplete = false;
				disp.flush();
				inter = blank;
			}	
		}
	}
		
	
	
}

void Executive::selectionPhase(Board& playerBoard)
{
	if(numberOfShips > 0)
	{
		row = ((disp.mouse_y())/(H/12));
		col = ((disp.mouse_x())/(W/24));
		infoAdds = background;
		if(vert == 1)infoAdds.draw_text(0,0,"Player:%d Orientation: %s Placing Ship of Length:%d",gridLines,0,1,13,playerBoard.getPlayer(),"Vertical",numberOfShips);
				else infoAdds.draw_text(0,0,"Player:%d Orientation: %s Placing Ship of Length:%d",gridLines,0,1,13,playerBoard.getPlayer(),"Horizontal",numberOfShips);
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
			if(vert == 1)infoAdds.draw_text(0,0,"Player:%d Orientation: %s Placing Ship of Length:%d",gridLines,0,1,13,playerBoard.getPlayer(),"Vertical",numberOfShips);
				else infoAdds.draw_text(0,0,"Player:%d Orientation: %s Placing Ship of Length:%d",gridLines,0,1,13,playerBoard.getPlayer(),"Horizontal",numberOfShips);
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
			if(vert == 1)infoAdds.draw_text(0,0,"Player:%d Orientation: %s Placing Ship of Length:%d",gridLines,0,1,13,playerBoard.getPlayer(),"Vertical",numberOfShips);
				else infoAdds.draw_text(0,0,"Player:%d Orientation: %s Placing Ship of Length:%d",gridLines,0,1,13,playerBoard.getPlayer(),"Horizontal",numberOfShips);
			disp.display(infoAdds);
			if(numberOfShips == 0)
			{
				disp.wait(1000);
				disp.flush();
			}
			
		}
	}
	else
	{
		if(playerBoard.getPlayer() == 1)
		{
			if(botGame == true)
            {
                inter.draw_text(W/2-30, H/2-4, "Right Click To Begin Attack Phase", white, 0, 33);
            }
            else
            {
                inter.draw_text(W/2-30, H/2-4, "Right Click To Begin Turn P2", white, 0, 33);
            }
			disp.display(inter);
			disp.wait();
			if((disp.button()&2))
			{
				disp.flush();
				numberOfShips = numberOfShipsChoice;
				p1shipsSelected = true;
                if(botGame == true)
                {
                    background.draw_text(W/2-30, 4, "Attack!", white, 0, 33);
					disp.display(background);
					p1CanAttack = true;
                }
				else{
                    loadBoard(p2Board);
                }
				inter = blank;
			}
		}
		else if(playerBoard.getPlayer() == 2)
		{
			inter.draw_text(W/2-30, H/2-4, "Right Click To Begin Turn P1", white, 0, 33);
			disp.display(inter);
			disp.wait();
			if((disp.button()&2))
			{
				disp.flush();
				p2shipsSelected = true;
				p1CanAttack = true;
				loadBoard(p1Board);
				inter = blank;
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


			if(board.getPlayer() == 1)
			{
				if(p2Board.getEntry(i,j) == -2)
				{
					background.draw_rectangle((W/24)*(j+13)+1,(H/12)*(i+2)+1, (W/24)*(j+14)-1, 
					(H/12)*(i+3)-1, yellow);
				}
				else if(p2Board.getEntry(i,j) == -1)
				{
					background.draw_rectangle((W/24)*(j+13)+1,(H/12)*(i+2)+1, (W/24)*(j+14)-1, 
					(H/12)*(i+3)-1, attacked);
				}

			}
			else if(board.getPlayer() == 2)
			{
				if(p1Board.getEntry(i,j) == -2)
				{
					background.draw_rectangle((W/24)*(j+13)+1,(H/12)*(i+2)+1, (W/24)*(j+14)-1, 
					(H/12)*(i+3)-1, yellow);
				}
				else if(p1Board.getEntry(i,j) == -1)
				{
					background.draw_rectangle((W/24)*(j+13)+1,(H/12)*(i+2)+1, (W/24)*(j+14)-1, 
					(H/12)*(i+3)-1, attacked);
				}
			}

		}
	}
	disp.display(background);
}

Executive::~Executive()
{

}
