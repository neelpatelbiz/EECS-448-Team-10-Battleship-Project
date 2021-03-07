#include "CImg.h"
#include <iostream>

int main()
{
  using namespace cimg_library;
  const unsigned char gridLines[3] = { 128,200,255}, attacked[3] = { 255,0,0 }, 
  defaultTile[3] = { 255,255,255 }; 
  unsigned int W = 1008, H = 504;
  int numberOfShips = 5;
  
  //create background

  CImg<unsigned char> background(W, H, 1, 3, 255); 
  background.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
  //CImg<unsigned char> SettingsSelect(2, 2, 1, 3, 255); 
  //SettingsSelect.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H).blur(2).normalize(0,128);
  
  //CImgList<unsigned char> backgrounds(background, background, false);

  //CImg<unsigned char> shipSelect(W,H,1,3,255);//ship select cimg to replace popup
  //shipSelect.assign();
  //numberOfShips = cimg::dialog("Number Of Ships","Enter the number of ships you would like to play with, up to a total of 6.", "1", "2","3","4","5","6", background, true) + 1;

  //std::cout<<numberOfShips;
  


  
  //.draw_rectangle(0,0,W-1,H-1,white,1.0f,~0U);
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      //if(//checkhitmethod())
      background.draw_rectangle((W/24)*(j+1)+1,(H/12)*(i+2)+1, 
      (W/24)*(j+2)-1, (H/12)*(i+3)-1, defaultTile);
      //else if(p2Ships.checkHit(i+1, j+1) == ".")
      
      background.draw_rectangle((W/24)*(j+13)+1,(H/12)*(i+2)+1, 
      (W/24)*(j+14)-1, (H/12)*(i+3)-1, defaultTile);
      // background.draw_rectangle((W/12)+(W/12)*j,(H/12)*i+(H/6), 
      // (W/12)*j+(W/6), (H/12)*i+((3*H)/12), gridLines, 1, ~0U);
    }
  }
  

  //create display
  CImgDisplay disp(background,"BattleShip",0,false,false);
  disp.move((CImgDisplay::screen_width() - disp.width())/2,(CImgDisplay::screen_height() - disp.height())/2);
  bool selectionPhase = true;
  int row = 0, col = 0, vert = 1;
  CImg<unsigned char> visu;
  while(!disp.is_closed())
  {
    //for(int i = 1; i <= numberOfShips; i++)
    //{
      
      if(numberOfShips > 0)
      {
        row = ((disp.mouse_y())/(H/12));
        col = ((disp.mouse_x())/(W/24));
        visu = background;
        visu.draw_text(0,0,"Orientation: %d tile=%d,%d",gridLines,0,1,13,vert,row,col);
        disp.display(visu);

        if(disp.is_keyARROWUP())vert = 1;
        if(disp.is_keyARROWDOWN())vert = 0;        
        if( ((((disp.mouse_x())/(W/24)) >= 1 && ((disp.mouse_x())/(W/24)) <=10 ) ||
        (((disp.mouse_x())/(W/24)) >= 13 && ((disp.mouse_x())/(W/24)) <=22))
        && ((disp.mouse_y())/(H/12)) <=11 && ((disp.mouse_y()-4)/(H/12)) >=2
        && disp.button()&1)
        {
          row = ((disp.mouse_y())/(H/12));
          col = ((disp.mouse_x())/(W/24));
          visu = background;
          visu.draw_text(0,0,"Orientation: %d tile=%d,%d",gridLines,0,1,13,vert,row,col);
          disp.display(visu);
          if(vert == 1)//draw vertically
          {
            if(((disp.mouse_y()/(W/12))/*+i*/+numberOfShips)<=11 /*&& playerBoard.addShip(row,column,vert,numberOfShips,) */) 
            { 
              for(int j=0; j<numberOfShips; j++)
                background.draw_rectangle((col*(W/24))+1, (row+j)*(H/12)+1, (col*(W/24))+(W/24)-1, (row+j)*(H/12)+(H/12)-1, attacked);
              //disp.wait();
            }           
          }
          else if(vert == 0)//draw horizontally
          {
            if(((((disp.mouse_x()/(H/12))/*+i*/+numberOfShips)<=23 && ((disp.mouse_x()/(H/12))>=13))|| ((disp.mouse_x()/(H/12))/*+i*/+numberOfShips)<=11)
            /*&& playerBoard.addShip(row,column,vert,numberOfShips,) */) 
            {
              for(int j=0; j<numberOfShips; j++)
                background.draw_rectangle((col+j)*(W/24)+1, row*(H/12)+1, (col+j)*(W/24)+(W/24)-1, row*(H/12)+(H/12)-1, attacked);
              //disp.wait();
            }
          }
          numberOfShips--;
        }
      }
      
    //}
  }
  
        
}

