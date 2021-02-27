#include "CImg.h"
#include <iostream>

int main()
{
        using namespace cimg_library;
        const unsigned char blue[] = { 128,200,255}, red[] = { 255,0,0 }, white[] = { 255,255,255 }; 
        unsigned int W = 400, H = 400;


        CImg<unsigned char> background;
        background.assign(W, H, 1, 3);
        background.display();
        
}
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