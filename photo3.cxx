//File: photo3.cxx 03/24/2011
//Written by: Kyle Staub
//E-mail: kyle.staub@colorado.edu
//This program takes a green screen shot of me and imposes it on a
//background of an explosion. 

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
//turns that pixel to the color of the background pixel.
void evaluate_color(int px, int py);
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
int main()
{
    int px, py;

    initwindow(S, S, "Explosion!", 0, 0, false); //Window 0
    readimagefile("explosion.jpg", 0, 0, S, S);
    initwindow(S, S, "Kyle!", 0, 0, false); //Window 1
    readimagefile("kyle.jpg", 0, 0, S, S);
    

    for(px = 0; px < S; ++px)
    {
	for(py = 0; py < S; ++py)
	{
	    evaluate_color(px, py);
	}

    }

    setcurrentwindow(1); //Making sure to display final image.
    
    delay(900000);
   
    
    return EXIT_SUCCESS;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void evaluate_color(int px, int py)
{
    //These two get the pixel of the background at px, py.
    setcurrentwindow(0);
    int background = getpixel(px, py);
    
    //These get the RBG values of the foreground.
    setcurrentwindow(1);
    int color, red, green, blue;
    color = getpixel(px, py);
    red = RED_VALUE(color);
    green = GREEN_VALUE(color);
    blue = BLUE_VALUE(color);

    if((red > 135 && green > 135 && blue > 135
	&& abs(red - green) < 15 && abs(green - blue) < 15
	&& abs(red - blue) < 15))
    {
	putpixel(px, py, background);
    }
}
//-----------------------------------------------------------------------------



