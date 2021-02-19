#ifndef SHIPS_H
#define SHIPS_H

#include <iostream>
#include <string>
/**
 * draw the ship. determine how ship in the board.
 * @author  Team 10
 * @version 19, Feb 2021
 */

class Ships
{
public:
  /**
 * constructor
 * @param  nothing
 */
  Ships();
  /**
 * check the state of destory, draw the syboml
 * @param  s it is symbol of ship
 */
  void buildShip(int);
  /**
* distructor
* @param  nothing
*/
  ~Ships();
  /**
* get the size form the gamer choice
* @param  s  of the size from the choice
*/
  void setSize(int s);
  /**
* get the hit form the gamer
* @param  hits make the number get bigger.
*/
  void hit();
  /**
* compare the hit with size to get the is the ship destory
* @param  hit, size form the function before
*/
  bool isDestroyed();

private:
  int size;
  int hits;
  bool destroyed;

};
#endif
