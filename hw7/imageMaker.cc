#include "imageMaker.h"
#include <iostream>
#include <fstream>

imageMaker::imageMaker(const char* fileName)
    : fileName(fileName), width(0), height(0), pixels(nullptr)
{
    this->fileName = fileName;
    readPPM(fileName);
}

imageMaker::~imageMaker(){
    delete[] pixels;
}

unsigned char* imageMaker::readPPM(const char* fileName)
{
    std::ifstream in(fileName, std::ios::binary);
    char magicNum[3];
    int maxPix;
    // parsing header data
    in >> magicNum;
    in >> width >> height;
    in >> maxPix;
    in.ignore(1); // for the /n
    // reading binary data
    int fullSize = (width * height * 3);
    delete[] pixels;
    pixels = new unsigned char[fullSize];
    // seems like .read is only suited for char arrays and not unsigned chars so i used reinterpret_cast
    in.read(reinterpret_cast<char*>(pixels), fullSize); // should be a band-aid fix until i find a better way of fixing this
    // close file
    in.close();
    // return pixels to be used for createPPM
    return pixels;
}

void imageMaker::makePPM(const char* fileName) const
{
    std::ofstream toMake(fileName, std::ios::binary);
    // writing header
    toMake << "P6\n";
    toMake << width << " " << height << "\n";
    toMake << "255\n";

    // write binary data
    int fullSize = width * height * 3;
    // i believe sizeof should work the same as creating the fullSize but if it breaks then i know what to do
    toMake.write(reinterpret_cast<char*>(pixels), fullSize); // it did in fact not work the same as creating fullSize
    toMake.close();
    std::cout << "image copied @copy.ppm!";
}

void imageMaker::operator+=(int value)
{
    int fullSize = width * height * 3;
    for(int i = 0; i < fullSize; i++)
    {
        int newValue = pixels[i] + value;
        if (newValue > 255)
        {
            newValue = 255;
        }
        if (newValue < 0)
        {
            newValue = 0;
        }
        pixels[i] = static_cast<unsigned char>(newValue);
    }
}