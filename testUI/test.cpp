#include "CImg.h"
#include <iostream>

int main()
{
  using namespace cimg_library;
  const unsigned char gridLines[] = { 128,200,255}, attacked[] = { 255,0,0 }, 
  defaultTile[] = { 255,255,255 }; 
  unsigned int W = 500, H = 500;
  int numberOfShips;
  
  //create background

  CImg<unsigned char> background(W, H, 1, 3, 255); 
  background.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
  CImg<unsigned char> SettingsSelect(2, 2, 1, 3, 255); 
  background.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
  /*
  CImg<unsigned char> attacked(W/15,H/15, 3, 255);
  CImg<unsigned char> defaultTile(W/15,H/15, 3, 255);
  CImg<unsigned char> missed(W/15,H/15, 3, 255);
  CImg<unsigned char> carrier (W/15,H/15, 3, 255);
  CImg<unsigned char> battleship (W/15,H/15, 3, 255);
  CImg<unsigned char> cruiser (W/15,H/15, 3, 255);
  CImg<unsigned char> destroyer (W/15,H/15, 3, 255);
  CImg<unsigned char> patrol (W/15,H/15, 3, 255);
  CImg<unsigned char> sub (W/15,H/15, 3, 255);
  */
  if(cimg::dialog("BASIC RULES",
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
  "6 ships: \nSub: (1x1), Patrol Boat: (1x2), Cruiser: (1x3), Destroyer: (1x4), Battleship: (1x5), Carrier: (1x6)\n\n"
  , "Start", "Quit",0,0,0,0,
  background, true))std::exit(0);

  numberOfShips = cimg::dialog("Number Of Ships","Enter the number of ships you would like to play with, up to a total of 6.", "1", "2","3","4","5","6", background, true) + 1;

  std::cout<<numberOfShips;
  
  //.draw_rectangle(0,0,W-1,H-1,white,1.0f,~0U);
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      //if(p2Ships.checkHit(i+1,j+1) == "S" || 
      //p2Ships.checkHit(i+1,j+1) == "P" ||
      //p2Ships.checkHit(i+1,j+1) == "c" ||
      //p2Ships.checkHit(i+1,j+1) == "D" ||
      //p2Ships.checkHit(i+1,j+1) == "B" ||
      //p2Ships.checkHit(i+1,j+1) == "C" ||)
      background.draw_rectangle((W/12)+(W/12)*j+1,(H/12)*i+(H/6)+1, 
      (W/12)*j+(W/6)-1, (H/12)*i+((3*H)/12)-1, attacked);
      //else if(p2Ships.checkHit(i+1, j+1) == ".")
      
      background.draw_rectangle((W/12)+(W/12)*j,(H/12)*i+(H/6), 
      (W/12)*j+(W/6), (H/12)*i+((3*H)/12), gridLines, 1, ~0U);
    }
  }
  

  //create display
  CImgDisplay disp(background,"BattleShip",0,false,true);
  disp.move((CImgDisplay::screen_width() - disp.width())/2,(CImgDisplay::screen_height() - disp.height())/2);

  while(!disp.is_closed())
  {
    if(disp.button()&1)
    {
      std::cout<<"tile=:"<<((disp.mouse_x()-4)/(W/12))-1<<", "<<((disp.mouse_y()-4)/(W/12))-2<<"\n";
      
    }
    
  }
  std::getchar();
        
}

/*
  The CImgList<T>::iterator type is defined as a CImg<T>*.
  You may use it like this:
  CImgList<> list;   // Assuming this image list is not empty
  for (CImgList<>::iterator it = list.begin(); it<list.end(); ++it) (*it).mirror('x');
  //if(shipArr[i][j] == //hitcondition){*it.//changestyle}
*/
/*
Button usage
//hex 1 for left mouse button
CImgDisplay disp(400,400);
while (!disp.is_closed()) {
  if (disp.button()&1) { // Left button clicked
    ...
  }
  if (disp.button()&2) { // Right button clicked
    ...
  }
  if (disp.button()&4) { // Middle button clicked
    ...
  }
  disp.wait();
}

//mouse pos functions: returns [0, height()-1] or -1 if pointer is outside of window
int mouse_x()const
int mouse_y()const



*/
