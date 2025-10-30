#include "imageMaker.h"
#include <iostream>
#include <fstream>

imageMaker::imageMaker(const char* fileName, int width, int height)
{
    this->width = width;
    this->height = height;
}

imageMaker::~imageMaker(){
}

unsigned char* imageMaker::readPPM(const char* fileName) const
{
    std::ifstream in(fileName, std::ios::binary);
    char magicNum[3];
    int maxPix;
    int width, height;
    // parsing header data
    in >> magicNum;
    in >> width >> height;
    in >> maxPix;

    // reading binary data
    int fullSize = ((width) * (height) * 3);
    unsigned char* pixels = (unsigned char*)malloc(fullSize);
    // seems like .read is only suited for char arrays and not unsigned chars so i used reinterpret_cast
    in.read(reinterpret_cast<char*>(pixels), fullSize); // should be a band-aid fix until i find a better way of fixing this
    // close file
    in.close();
    // return pixels to be used for createPPM
    return pixels;
}

void imageMaker::makePPM(const char* fileName, unsigned char* pixels, int width, int height) const
{
    std::ofstream toMake(fileName, std::ios::binary);
    // writing header
    toMake << "P6" << std::endl;
    toMake << width << height << std::endl;
    toMake << "255" << std::endl;

    // write binary data
    toMake.write(reinterpret_cast<char*>(pixels), sizeof(pixels)); // i believe sizeof should work the same as creating the fullSize but if it breaks then i know what to do
    std::cout << "image copied @copy.ppm!";

    toMake.close();
}