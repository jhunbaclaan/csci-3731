#include <cstdio>

bool checkBound(float x, float y)
{
    return ((x * x) + (y * y) > 4.0);
}
// reused methods from 2.3, since i know it already works
float xprime(float a, float x, float y)
{
    float result = (x*x) - (y*y)+a;
    return result;
}
float yprime(float b, float x, float y)
{
    float result = 2*(x*y) + b;
    return result;
}