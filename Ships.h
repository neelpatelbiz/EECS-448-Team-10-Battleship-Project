#ifndef SHIPS_H
#define SHIPS_H

#include <iostream>
#include <string>
/**
 * Ship class
 * @author  Team 10
 * @version 19, Feb 2021
 */

class Ships
{
public:
  /**
 * constructor
 * @param
 */
  Ships();
  /**
 * check the state of destory, draw the symbol
 * @param int is the size of ship onject
 *  Changes ship object attributes
 */
  void buildShip(int);
  /**
* destructor
* returns memory
* @param
*/
  ~Ships();
  /**
* User inputs size of Ship
* @param  int that corresponds to size
*/
  void setSize(int s);
  /**
* Increases the hit counter by 1
* @param
*/
  void hit();
  /**
* compare the hit counter with size counter to check if they equal == ship destroyed
* @param 
*/
  bool isDestroyed();

private:
  int size;
  int hits;
  bool destroyed;

};
#endif
