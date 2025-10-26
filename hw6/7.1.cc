#include <cstdio>
#include "images.h"

int main(int argc, char** argv)
{
    int width, height;
    unsigned char* pixels = readPPM("test.ppm", &width, &height);

    createImage("test.jpg", pixels, width, height, 100);
}