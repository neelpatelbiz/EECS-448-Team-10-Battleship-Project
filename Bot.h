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
        int lastXhit, lastYhit, iterations, attackStatus, nextX, nextY;

        /**
         *Bot is given p1's board to attack. Based on the difficulty of the bot, it will decide where to attack.
         *@param toAttack the board the bot will attack
        */
        bool easyAttack(Board& toAttack);

        /**
         *Bot is given p1's board to attack. Based on the difficulty of the bot, it will decide where to attack.
         *@param toAttack the board the bot will attack
        */
        bool mediumAttack(Board& toAttack);

        /**
         *Bot is given p1's board to attack. Based on the difficulty of the bot, it will decide where to attack.
         *@param toAttack the board the bot will attack
        */
        bool cheatAttack(Board& toAttack);

        /**
         *Find the next X any Y positions to attack (mediumAttack helper function)
        */
        bool findNext();
};
#endif