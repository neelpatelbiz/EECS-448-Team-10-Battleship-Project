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
        // const unsigned char bluegreen[] = {85, 78, 255 };
        // CImg<unsigned char> bg(w,h,1,3);

        // bg.draw_circle(w/2,h/2,100, bluegreen);

        // bg.display();
}
