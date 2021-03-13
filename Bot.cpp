#include "Bot.h"
Bot::Bot()
{
	botState = 'W';
	surroundCount = 0;
	bothDirections = false;
	i=0;
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
		return(mediumAttack(board));
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
	
	if(botState == 'W')//bot is waiting for a hit
	{
		srand(time(NULL));
		do
		{
			firstXHit = std::rand()%10;
			firstYHit = std::rand()%10;
			attackStatus = board.attack(firstYHit, firstXHit);
		} while (attackStatus == -2);//keep looking for possible attack tiles
		if(attackStatus == -1)//bot recognizes a hit
		{
			botState = 'S';//bot will now check surrounding tiles
		}
		else if(attackStatus == 6)//bot won the game off its random hit
		{
			return (true);
		}
		else//bot either sunk a ship or missed -> does not need to remember anything
		{
			firstXHit = 0;
			firstYHit = 0;
		}
		return (false);
	}
	else if(botState == 'S')//bot has a single hit and needs to check surrounding tiles
	{
		return(checkSurround(board));
	}
	else if(botState == 'P')//bot has registered a second hit and must attempt to sink entire ship
	{
		attackStatus = -3;//if attackStatus does not change before evaluation, go back to firing randomly
		if(orientation == 0)
		{
			if( (direction == 0 && firstXHit+i>=0) || (direction == 1 && firstXHit+i<=9) )
			{
				attackStatus = board.attack(firstYHit, firstXHit+i);
				
			}
			if(attackStatus == -2 || attackStatus == -3)//could not attack in the original direction
			{
				if(!bothDirections && direction == 0 && firstXHit+1<=9){
					i=2;
					direction = (direction +1)%2;
					attackStatus = board.attack(firstYHit, firstXHit+1);
					bothDirections = true;
				}
				else if(!bothDirections && direction == 1 && firstXHit-1>=0){
					i=-2;
					direction = (direction +1)%2;
					attackStatus = board.attack(firstYHit, firstXHit-1);
					bothDirections = true;
				}
				else // could not attack in either direction
				{
					botState = 'W';
					surroundCount = 0;
					bothDirections = false;
					return false;
				}
			}
			
		}
		else if(orientation == 1)
		{
			if( (direction == 0 && firstYHit+i>=0) || (direction == 1 && firstYHit+i<=9) )
			{
				attackStatus = board.attack(firstYHit+i, firstXHit);
				
			}
			if(attackStatus == -2 || attackStatus == -3)//could not attack in the original direction
			{
				if(!bothDirections && direction == 0 && firstYHit+1<=9){
					i=2;
					direction = (direction +1)%2;
					attackStatus = board.attack(firstYHit+1, firstXHit);
					bothDirections = true;
				}
				else if(!bothDirections && direction == 1 && firstYHit-1>=0){
					i=-2;
					direction = (direction +1)%2;
					attackStatus = board.attack(firstYHit-1, firstXHit);
					bothDirections = true;
				}
				else // could not attack in either direction
				{
					botState = 'W';
					surroundCount = 0;
					bothDirections = false;
					return false;
				}
			}
		}
		
		if(attackStatus == -1)
		{
			if(direction == 0){
				i--;
			}
			else{
				i++;
			}
			return false;
		}
		else if(attackStatus == 6)
		{
			return (true);
		}
		else if(attackStatus > 0)
		{
			surroundCount = 0;
			bothDirections = false;
			botState = 'W';
			return false;
		}
		else if(attackStatus == 0)
		{
			if(bothDirections == false)
			{
				if(direction == 0){
					i = 1;
				}
				else{
					i = -1;
				}
				direction = (direction + 1)%2;
				bothDirections = true;
			}
			else
			{
				botState = 'W';
				surroundCount = 0;
				bothDirections = false;
			}
			return false;
		}

	}

}

bool Bot::checkSurround(Board& board)
{
	switch(surroundCount)
	{
		case(0):
			if(firstYHit-1>=0)
			{
				attackStatus = board.attack(firstYHit-1, firstXHit);
				if(attackStatus == -1)
				{
					botState = 'P';
					orientation = 1;
					direction = 0;
					i=-2;
					return false;
					//surroundCount = 0;
					break;
				}
				else if(attackStatus == 6)
				{
					return (true);
					break;
				}
				else if(attackStatus > 0)
				{
					botState = 'W';
					return false;
					break;
				}
				else if(attackStatus == -2)
				{
					surroundCount++;
				}
				else if(attackStatus == 0)
				{
					surroundCount++;
					return false;
					break;
				}
			}
			else
			{
				surroundCount++;
			}
		case(1):
			if(firstXHit+1<=9)
			{
				attackStatus = board.attack(firstYHit, firstXHit+1 );
				if(attackStatus == -1)
				{
					botState = 'P';
					orientation = 0;
					direction = 1;
					i=2;
					return false;
					//surroundCount = 0;
					break;
				}
				else if(attackStatus == 6)
				{
					return (true);
					break;
				}
				else if(attackStatus > 0)
				{
					botState = 'W';
					return false;
					break;
				}
				else if(attackStatus == -2)
				{
					surroundCount++;
				}
				else if(attackStatus == 0)
				{
					surroundCount++;
					return false;
					break;
				}
			}
			else
			{
				surroundCount++;
			}
		case(2):
			if(firstYHit+1<=9)
			{
				attackStatus = board.attack(firstYHit+1, firstXHit);
				if(attackStatus == -1)
				{
					botState = 'P';
					orientation = 1;
					direction = 1;
					i=2;
					return false;
					//surroundCount = 0;
					break;
				}
				else if(attackStatus == 6)
				{
					return (true);
					break;
				}
				else if(attackStatus > 0)
				{
					botState = 'W';
					return false;
					break;
				}
				else if(attackStatus == -2)
				{
					surroundCount++;
				}
				else if(attackStatus == 0)
				{
					surroundCount++;
					return false;
					break;
				}
			}
			else
			{
				surroundCount++;
			}
		case(3):
			if(firstXHit-1>=0)
			{
				attackStatus = board.attack(firstYHit, firstXHit-1);
				if(attackStatus == -1)
				{
					botState = 'P';
					orientation = 0;
					direction = 0;
					i=-2;
					return false;
					//surroundCount = 0;
					break;
				}
				else if(attackStatus == 6)
				{
					return (true);
					break;
				}
				else if(attackStatus > 0)
				{
					botState = 'W';
					return false;
					break;
				}
				else if(attackStatus == 0 || attackStatus == -2)
				{
					surroundCount=0;
					botState = 'W';
					return false;
					break;
				}
			}
			else
			{
				surroundCount=0;
				botState = 'W';
				break;
			}
		default:
			break;
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