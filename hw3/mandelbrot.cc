#include <cstdio>

// checkBound stays since we only need to worry about changing the mandelbrot function
bool checkBound(float x, float y)
{
    return ((x * x) + (y * y) > 4.0);
}
// adding another function that returns updated x & y
// this looks pretty sloppy so if this is reused at some point in the future i think i'll make it more efficient
void performMandelbrot(float a, float b, float* x, float* y)
{
    // you can dereference x & y to use them in the math of the function
    float realX = *x;
    float realY = *y;

    float xprime = (realX * realX) - (realY * realY) + a;
    float yprime = 2*(realX * realY) + b;

    // ..then turn them back into pointers to be returned
    *x = xprime;
    *y = yprime;
}