#include "Bot.h"
Bot::Bot()
{
	iterations = 0;
	lastXhit = -1;
	lastYhit = -1;
	nextX = 0;
	nextY = 0;
}
void Bot::placeShips(int numShips, Board& board)
{
	int vert, x, y;
	bool canPlace = false;
	std::srand(time(NULL));
	for(int i=numShips; i>0; i--)
	{
		do
		{
			vert = std::rand()%2;
			x = std::rand()%10;
			y = std::rand()%10;
			canPlace = board.addShip(x,y,vert,i);
		} while(!canPlace);
	}
}
bool Bot::botAttack(int difficulty, Board& board)
{
	if(difficulty == 1)
	{
		return(easyAttack(board));
	}
	else if(difficulty == 2)
	{

	}
	else if (difficulty == 3)
	{
		return(cheatAttack(board));
	}
}

bool Bot::easyAttack(Board& board)
{
	srand (time(NULL));
	do
	{
		attackStatus = board.attack(std::rand()%10, std::rand()%10);
	} while (attackStatus == -2);
	if(attackStatus == 6)
	{
		return (true);
	}
}

bool Bot::mediumAttack(Board& board)
{
	
	if(lastXhit == -1)
	{
		do
		{
			nextX = std::rand()%10;
			nextY = std::rand()%10;
			attackStatus = board.attack(std::rand()%10, std::rand()%10);
		} while (attackStatus == -2);
		if(attackStatus == -1)
		{
			lastXhit = nextX;
			lastYhit = nextY;
			iterations++;
		}
		else if(attackStatus == 6)
		{
			return true;
		}
	}
	else
	{
		findNext();

	}
}
bool Bot::findNext()
{
	if(iterations == 1)
	{
		if(nextY-1>0)
		{
			nextX=lastXhit;
			nextY=lastYhit-1;
		}
	}
	else if(iterations == 2)
	{	
		if(nextX+1<9)
		{
			nextX=lastXhit+1;
			nextY= lastYhit;
		}
	}
	else if(iterations == 3)
	{
		if(nextY+1<9)
		{
			nextX=lastXhit;
			nextY= lastYhit+1;
		}
	}
	else if(iterations == 4)
	{
		if(nextX+1<9)
		{
			nextX=lastXhit+1;
			nextY= lastYhit;
		}
	}
}
bool Bot::cheatAttack(Board& board)
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(board.getEntry(i,j)>0)
			{
				if(board.attack(i,j) == 6)
				{
					return (true);
				}
				else
				{
					return (false);
				}
				break;
				break;
			}
		}
	}
}


/*
void Executive::botRun()
{
	disp.move((CImgDisplay::screen_width() - disp.width())/2,(CImgDisplay::screen_height() - disp.height())/2);
	
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ())
	{
		if(!gameConfigured)
		{
			printMenu();
		}
		if(gameConfigured&&!p1shipsSelected)
		{
			botSelectionPhase(p1Board);
		}
		if(p1CanAttack == true)
		{
			attackPhase(p1Board);
		}
	}
}
void Executive::botSelectionPhase(Board& playerBoard)
{
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
			if(numberOfShips == 0)
			{
				disp.wait(1000);
				disp.flush();
			}
			
		}
	}
	else
	{
		//disp.wait(1000);
		//disp.flush();
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
                    background.draw_text(W/2-30, H/2-4, "Attack!", white, 0, 33);
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
	*/