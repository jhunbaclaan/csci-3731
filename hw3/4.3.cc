/*
@@ created by jhun baclaan, d.o.c. sep. 19 2025
a lot of the code is copy and pasted from 3.3; i only made modifications for the changed mandelbrot functions
as well as file writing
*/

#include <cstdio>
// header file inclusion
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
    
    // filewriting; open the file before the loop!
    FILE* fp = fopen("drawing", "w"); // pretty much just used the sample code from 4.4 in the book
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
                // use new mandelbrot function for x/y; remember that you have to call b/c it uses pointers
                performMandelbrot(a, b, &x, &y); // it works!
                if(checkBound(x, y) == true)
                {
                    fprintf(fp, " ");
                    break;
                }
                else if (z == 999)
                {
                    fprintf(fp, "*");
                }
            }
            // adding is required to a & b or else the image will be very linear
            a += 0.03255; // picking some arbitrary number
        }
        a = -2.0; // reset, since new column
        b += 0.0458572; // picking some arbitrary number
        fprintf(fp, "\n"); // newline for the next row
    }
    fclose(fp); // close only after iteration is done
}