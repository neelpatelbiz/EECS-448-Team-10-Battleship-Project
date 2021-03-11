#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "CImg.h"
#include "Board.h"
#include "Bot.h"

using namespace cimg_library;
class Executive
{
public:
	
	/// Main function that executes the PRINTMENU and GAME function
	void run();

	
	/// Constructor for Executive class
	/** Constructor that initializes instances for ships, for two platyers.
	 */
    Executive();

	/// Destructor for Executive class
	/// Deallocates the memory previously reserved. 
    ~Executive();

private:
	unsigned int W, H; 
	CImg<unsigned char> gameTypeSelect;
	CImg<unsigned char> botDifficultySelect;
	CImg<unsigned char> shipNumSelect;
	CImg<unsigned char> background;
	CImg<unsigned char> blankGrid;
	CImg<unsigned char> infoAdds;
	CImg<unsigned char> inter;
	CImg<unsigned char> blank;
	CImg<unsigned char> youWin;
	CImgDisplay disp;
	const unsigned char** shipColors;
	const unsigned char gridLines[3]= { 128,200,255}, defaultTile[3] = { 255,255,255 };
	const unsigned char attacked[3] = { 255,0,0 }, missedAttack[3] = {255,255, 0}, pendingAttack[3] = {201,72,194};
	const unsigned char ship1[3] = { 203,174,124}, ship2[3] = { 189,203,106 }, ship3[3] = {141,203,106 },
	ship4[3] = {106,203,168}, ship5[3] = {106, 189, 203};
	const unsigned char blue[3] = { 128,200,255}, red[3] = { 255,0,0 }, white[3] = { 255,255,255 },
	yellow[3] = {255,255, 0};

	Bot bot;
	bool botGame;
	bool difficultyChosen;
	bool gameTypeChosen;
	int difficulty;
	int numberOfShipsChoice;
	int numberOfShips;
	bool gameConfigured;
	bool p1shipsSelected;
	bool p2shipsSelected;
	bool p1CanAttack;
	bool p2CanAttack;
	bool attackComplete;
	int attackStatus;
	bool switchPlayer;
	Board p1Board;
	Board p2Board;

	int vert,row,col;

	/** 
	 * Bot Game or Local Game Screen 
	 */ 
	void gameType();

	/** 
	 * Select Bot Difficulty
	 */ 
	void botDifficulty();
	
	/** 
	 * ShipSelection Screen 
	  */ 
	void printMenu();

	/**
	 * opens CImgDisplay allowing player to select ship positions
	 */
	void selectionPhase(Board& playerBoard);

	/**
	 * opens CImgDisplay allowing player to select attack positions
	 * @param playerBoard of player attacking
	 */
	void attackPhase(Board& playerBoard);

	/**
	 * displays board which must be right-clicked to switch player turn
	 */
	//void switchScreen();

	/**
	 * loads colored tiles onto CImg of battleship boards
	 * @param board of player being attacked
	 */
	void loadBoard(const Board& board);
	

	/// Main function that runs initializes the multidimensional array and guides the user through the game
	/**  Function initializes integers numberOfShips, row, vert amd character column. 
	 *   then prompts player 1 to enter integers to first get the amount of ships max 6.
	 *   then prompts player 1 to place the ship in the grid. 
	 * 	 then prompts player 1 to see if they want a vertical alignment for the chosen ship
	 *   then loops for the amount of ships chosen and then shows the placement of ships before clearing the screen.
	 * 
	 *   Do the same thing on loop for player 2. 
	 * 
	 *   Initializes a win counter, then uses the Board instances to execute the game where the players static
	 *   ships locations are found. loops between player 1 and 2 until all ships instances of either player 1 or 2
	 *   are Hit.
	 */
	void Game();

};
#endif
