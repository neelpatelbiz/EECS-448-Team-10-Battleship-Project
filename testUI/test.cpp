#include "CImg.h"
#include <iostream>

int main()
{
        using namespace cimg_library;
        const unsigned char blue[] = { 128,200,255}, red[] = { 255,0,0 }, white[] = { 255,255,255 };
        
        
        unsigned int w = 500;
        unsigned int h = 500;

        CImg<unsigned char> 
        CImgDisplay disp(w,h,"Title", 0, false, false);
        disp.display("10X10Grid.jpg");
        // const unsigned char bluegreen[] = {85, 78, 255 };
        // CImg<unsigned char> bg(w,h,1,3);

        // bg.draw_circle(w/2,h/2,100, bluegreen);

        // bg.display();
}
