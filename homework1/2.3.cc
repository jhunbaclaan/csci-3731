/*
@@ created by jhun baclaan, d.o.c aug. 28 2025
mandelbrot set program that uses static values a & b iteratively with scaling values x & y
*/

#include <cstdio>

// simplifying the mandelbrot equations by making functions
// interestingly functions have to be put above the main method (unlike java where they can js be anywhere outside)
// it's a strange adjustment
int xprime(int a, int x, int y)
{
    int result = (x*x)- (y*y)+a;
    return result;
}
int yprime(int b, int x, int y)
{
    int result = 2*(x*y) + b;
    return result;
}

// main
int main(int argc, char** agv)
{
    // initialization and starting values; a & b are picked by me
    int a = 2;
    int b = 3;
    // x & y start as 0 as given by the problem
    int x = 0;
    int y = 0;

    /*
    iteration is interesting. i dont know how long we're supposed to iterate for
    so maybe i'll make a user system that continues to iterate if the user confirms?
    not sure.
    */
    // iteration processsss
    printf("iteration 1: a = %d, b = %d, x = %d, y = %d\n", a,b,x,y);
    x = xprime(a,x,y);
    y = yprime(b,x,y);
    printf("iteration 2: a = %d, b = %d, x = %d, y = %d\n", a,b,x,y);
    
}
