#include "imageMaker.h"
int main(int args, char** agv)
{
    imageMaker img("test.ppm");
    img+=(-80);
    img.makePPM("copy.ppm");
}