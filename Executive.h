#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "CImg.h"
#include "Board.h"
#include "Ships.h"

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
	int numberOfShips;
	unsigned int W, H; 
	CImg<unsigned char> background;
	CImg<unsigned char> blankGrid;
	CImgDisplay disp;
	const unsigned char gridLines[3]= { 128,200,255};
	const unsigned char attacked[3] = { 255,0,0 };
	const unsigned char defaultTile[3] = { 255,255,255 };

	Board p1Board;
	Board p2Board;


	/// Outputs a choice for instructions for the game
	/** Main Menu fuction for the Game, Show a intro screen and how to play with the rules. 
		Has a loop built into it that shows the rules.
		*/ 
	void printMenu();

	/**
	 * opens CImgDisplay allowing plpayer to select ship positions
	 */
	void selectionPhase(Board& playerBoard);


	/**
	 * Restores background to its original state with blank grids.
	 */
	void cleanUp();

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
