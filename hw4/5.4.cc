#include <cstdio>
#include "analysis.h"

int main(int args, char** agv)
{
    // filename
    const char* fileName = "test.ppm";
    char magicNum[3]; // 3 instead of 2 to account for the null character
    int width, height, maximum;

    // testing functions
    returnImage(fileName, magicNum, &width, &height, &maximum);
    // testing info grabbing from returnImage
    printf("file name: %s\n", fileName);
    printf("magic number: %s\n", magicNum);
    printf("width: %d, height: %d, maximum pixel value: %d\n", width, height, maximum);

    createImage(fileName);

}
