#ifndef BOT_H
#define BOT_H
#include "Board.h"
#include <cstdlib>
class Bot
{
    public:
        /**
         *Bot Constructor
        */
        Bot();

        /**
         *Bot is given p1's board to attack. Based on the difficulty of the bot, it will decide where to attack.
         *@param difficulty determines method bot will use to determine attack position
         *@param toAttack the board the bot will attack
        */
        bool botAttack(int difficulty, Board& toAttack);

        /**
         *Bot places their ships on the board provided
         *@param numShips number of Ships for bot to place
         *@param botBoard the board the bot will use
        */
        void placeShips(int numShips, Board& botBoard);

    private:
        int attackStatus;
        int firstXHit, firstYHit, surroundCount, orientation, direction, hitList[10], i;
        char botState;
        bool bothDirections;

        /**
         *Bot attacks randomly
         *@param toAttack the board the bot will attack
        */
        bool easyAttack(Board& toAttack);

        /**
         *Bot keeps track of hit to attack adjacent pieces
         *@param toAttack the board the bot will attack
        */
        bool mediumAttack(Board& toAttack);

        /**
         *mediumAttack helper function to check adjacent tiles from the original hit
         *@param toAttack the board the bot will attack
        */
        bool checkSurround(Board& board);

        /**
         *Bot knows where pieces are
         *@param toAttack the board the bot will attack
        */
        bool cheatAttack(Board& toAttack);

};
#endif