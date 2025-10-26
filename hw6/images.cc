/*
NOTE: much of this code is literally copy and pasted from 5.4.
there are modifications that i will point out in the code, but yeahhh lol a lot of this is just reused.
*/

#include <cstdio>
#include <cstdlib>
#include <jpeglib.h>

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
unsigned char* readPPM(const char* fileName, int* width, int* height)
{
    FILE* fileptr;
    fileptr = fopen(fileName, "rb");
    // check file format 
    if (!isPPM(fileName))
    {
        printf("%s\n", "file is not of .ppm type!");
        return NULL; // added null return to make the check step easier.. if/else is too inefficient
    }
    char magicNum[3];
    int maxPix;
    fscanf(fileptr, "%s", magicNum);
    fscanf(fileptr, "%d %d\n", width, height);
    fscanf(fileptr, "%d\n", &maxPix);
    // step three: get binary pixel data; use unformatted i/o and unsigned chars
    // 'every pixel' = width * height. so, take the binary data of width*height pixels?
    int fullSize = ((*width) * (*height) * 3); // dereference width & height to use in the math
    unsigned char* pixels = (unsigned char*)malloc(fullSize);
    // unformatted read via fread using sizeof; this works
    fread(pixels, 1, fullSize, fileptr);
    // close file
    fclose(fileptr);
    
    return pixels;
}
/*
* writing the image copy
* the idea is that attributes will be copied over from the original using returnImage
* basically dereferencing magicNum, width, height, maxPix to brute force a carbon copy
*/
void createImage(const char* fileName, unsigned char* img, int width, int height, int quality)
{
    // creating structs for the jpg image
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    // image to be made
    FILE* toMake;
    toMake = fopen(fileName, "wb");

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, toMake);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3; // 3 = rgb
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality, TRUE);

    // start conversion
    jpeg_start_compress(&cinfo, TRUE);

    JSAMPROW row_pointer;
    while(cinfo.next_scanline < cinfo.image_height)
    {
        row_pointer = (JSAMPROW)&img[cinfo.next_scanline * width * 3];
        jpeg_write_scanlines(&cinfo, &row_pointer, 1);
    }

    // end conversion
    jpeg_finish_compress(&cinfo);
    fclose(toMake);
    // release data
    jpeg_destroy_compress(&cinfo);

    printf("image created @test.jpg!\n");
}