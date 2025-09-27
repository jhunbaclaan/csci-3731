#include <cstdio>

// reading ppm file
// step one: initial check
bool isPPM(const char* fileName)
{
    FILE* fileptr;
    fileptr = fopen(fileName, "rb");
    char magicNum[3];
    // store the first two characters of the header into a string magicNum
    // hopefully this stores p6
    fread(magicNum, 1, 2, fileptr);
    magicNum[2] = '\0'; // hardcode the null character
    fclose(fileptr);
    // check for p6
    if (magicNum[0] == 'P' && magicNum[1] == '6')
    {
        return true;
    }
    else return false;
    
}
// step two: parse file, get header info
void returnImage (const char* fileName, char* magicNum, int* width, int* height, int* maxPix)
{
    FILE* fileptr;
    fileptr = fopen(fileName, "rb");
    // check file format 
    if (!isPPM(fileName))
    {
        printf("%s\n", "file is not of .ppm type!");
    }
    else
    {
        fscanf(fileptr, "%s", magicNum);
        fscanf(fileptr, "%d %d\n", width, height);
        fscanf(fileptr, "%d\n", maxPix);
        // print header
        printf("%s\n %d %d\n %d\n", magicNum, *width, *height, *maxPix);
        // step three: get binary pixel data; use unformatted i/o and unsigned chars
        // 'every pixel' = width * height. so, take the binary data of width*height pixels?
        int fullSize = ((*width) * (*height)); // dereference width & height to use in the math
        unsigned char* pixels = new unsigned char[fullSize];
        // unformatted read via fread using sizeof; this works
        while(fread(pixels, sizeof(int), 128, fileptr))
        {
            printf("%s", pixels);
        }
        
    }
    // close file
    fclose(fileptr);
}
/*
* writing the image copy
* the idea is that attributes will be copied over from the original using returnImage
* basically dereferencing magicNum, width, height, maxPix to brute force a carbon copy
*/
void createImage(const char* fileName)
{
    // initialize values to be changed by returnImage
    char magicNum[3];
    int width = 0;
    int height = 0;
    int maxPix = 0;

    // opening original file
    FILE* original;
    original = fopen(fileName, "rb");
    // image to be made
    FILE* toMake;
    toMake = fopen("copy.ppm", "wb");

    // copy attributes over from original file to the new copy..
    fscanf(original, "%2s", magicNum);
    fscanf(original, "%d %d", &width, &height);
    fscanf(original, "%d", &maxPix);
    // printing attributes
    fprintf(toMake, "%s\n", magicNum);
    fprintf(toMake, "%d %d\n", width, height);
    fprintf(toMake, "%d ", maxPix);

    fgetc(original); // the \n....

    // printing the pixel data; just the same approach as getting the pixel data... make an unsigned char array, then fwrite
    int fullSize = ((width * height) * 3); // multiply by 3 since 3 bytes per pixel
    unsigned char* pixels = new unsigned char[fullSize];
    // reading & writing
    fread(pixels, 1, fullSize, original);
    fwrite(pixels, 1, fullSize, toMake);

    fclose(original);
    fclose(toMake);

    printf("image copied @copy.ppm!\n");
}