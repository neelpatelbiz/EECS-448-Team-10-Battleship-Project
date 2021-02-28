#include "CImg.h"
#include <iostream>

int main()
{
        using namespace cimg_library;
        const unsigned char blue[] = { 128,200,255}, red[] = { 255,0,0 }, 
	      white[] = { 255,255,255 }; 
        unsigned int W = 500, H = 500, horOffset = 100, verOffset = 100, sqWid=W/15,
		     sqHeight=H/15;
        
        //create background
        CImg<unsigned char> background(W, H, 1, 3, 255); 
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

        background.assign(64,64,1,3,0).noise(60).draw_plasma().resize(W,H)
		.blur(2).normalize(0,128);
        //.draw_rectangle(0,0,W-1,H-1,white,1.0f,~0U);
        for(int i=0;i<10;i++)
        {
          for(int j=0;j<10;j++)
          {
            background.draw_rectangle((W/12)+(W/12)*i,(H/12)*j+(H/6), 
		(W/12)*i+(W/6), (H/12)*j+((3*H)/12), blue, 1, ~0U);
          }
        }
        

        //create display
        CImgDisplay disp(background,"CImg Tetris",0,false,true);
        disp.move((CImgDisplay::screen_width() - disp.width())/2,
			(CImgDisplay::screen_height() - disp.height())/2);
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
