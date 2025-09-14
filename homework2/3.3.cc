/*
@@ created by jhun baclaan, d.o.c. sep. 8 2025
builds off of 2.3; uses static values a & b as well as scaling values x & y
this time, the program visualizes the mandelbrot set using asterisks and whitespaces

09/14/25: i hate being sick so, so much.
*/

#include <cstdio>
// header file inclusion
//#include mandelbrot.cc was wondering why my makefile was yelling at me.. forgot that you shouldn't include .cc's. lesson learned
#include "converge.h"

int main(int args, char** agv)
{
    // init values
    float x = 0.0;
    float y = 0.0;
    // a & b are again picked by me
    // found that -2.0 & -1.5 are the best values for making a shape
    float a = -2.0;
    float b = -1.5;
    
    // creating the loop; first loop is for the rows
    // using 80 since the book advises it
    for(int i = 0; i < 80; i++)
    {
        for(int n = 0; n < 80; n++) // rows
        {
            // need this step for resetting every iteration
            x = 0.0;
            y = 0.0;
            for(int z = 0; z < 1000; z++)
            {
                x = xprime(a, x, y);
                y = yprime(b, x, y);
                if(checkBound(x, y) == true)
                {
                    printf(" ");
                    break;
                }
                else if (z == 999)
                {
                    printf("*");
                }
            }
            // adding is required to a & b or else the image will be very linear
            a += 0.03255; // picking some arbitrary number
        }
        a = -2.0; // reset, since new column
        b += 0.0458572; // picking some arbitrary number
        printf("\n"); // newline for the next row
    }
}