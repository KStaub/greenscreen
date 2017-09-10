//File: photo2.cxx 03/24/2011
//Written by: Kyle Staub
//E-mail: kyle.staub@colorado.edu
//This program shows a picture of me, then turns all of the background pixels
//to green. 

//Directives:
#include<cstdlib>
#include<cmath>
#include<graphics.h>
#include<iostream>
#include<string>
using namespace std;
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//This constant gives the dimensions of the window.
int const S = 600;
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//This function determines a pixel's "whiteness" and if it returns true,
//turns that pixel green.
void evaluate_color(int px, int py);
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
int main()
{

    int px, py;
    
    initwindow(S, S, "Me too! (two)");
    readimagefile("kyle.jpg", 0, 0, S, S);

    for(px = 0; px < S; ++px)
    {
	for(py = 0; py < S; ++py)
	{
	    evaluate_color(px, py);
	}

    }

    delay(900000);
    
    return EXIT_SUCCESS;
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
void evaluate_color(int px, int py)
{
    int color, red, green, blue;

    //RBG values of each individual pixel.
    color = getpixel(px, py);
    red = RED_VALUE(color);
    green = GREEN_VALUE(color);
    blue = BLUE_VALUE(color);

    //Lots of conditions to ensure the pixel is white.
    if(red > 135 && green > 135 && blue > 135
       && abs(red - green) < 15 && abs(green - blue) < 15
	    && abs(red - blue) < 15)
    {
		putpixel(px, py, GREEN);
    }
}
//-----------------------------------------------------------------------------
