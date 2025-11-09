#include "imageMaker.h"
int main(int args, char** agv)
{
    imageMaker img("test.ppm");
    img+=(-80); // negative values darkens the image, positive values brighten it; -80 consumes my poor professor's dog with darkness....
    img.makePPM("copy.ppm");
}