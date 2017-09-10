//File: photo1.cxx 03/24/2011
//Written by: Kyle Staub
//E-mail: kyle.staub@colorado.edu
//This program shows a picture of me, and returns a pixel value for every
//location clicked.

//Directives:
#include<cstdlib>
#include<cmath>
#include<graphics.h>
#include<iostream>
#include<string>
using namespace std;
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//This constant describes the window size.
int const S = 600;
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//This function gets a mouseclick, and returns it's color values for red,
//green, and blue, and outputs them to the screen.
void find_color();
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
int main()
{
    initwindow(S, S, "Me!");
    readimagefile("kyle.jpg", 0, 0, S, S);
    
    while(true)
    {
	find_color();
    }
    return EXIT_SUCCESS;
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
void find_color()
{
    int px, py;
    int color; //Color value of get_pixel.
    int red, green, blue; //Values for RBG.
    if(ismouseclick(WM_LBUTTONDOWN))
    {
	//Here we get px and py and color.
	getmouseclick(WM_LBUTTONDOWN, px, py);
	color = getpixel(px, py);

	//Here we use color to get the RGB values at px, py. 
	red = RED_VALUE(color);
	green = GREEN_VALUE(color);
	blue = BLUE_VALUE(color);

	//Here we output those values to the screen.
	cout << red << endl;
	cout << green << endl;
	cout << blue << endl;
    }
	
}
//-----------------------------------------------------------------------------

