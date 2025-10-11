/*
@jhunbaclaan; created by jhun baclaan, d.o.c. oct. 5
major modifications include the inclusion of 2d arrays & the 1d unsigned char array
ppm image written to @mandelbrot.ppm
*/

#include <cstdio>
#include <cstdlib>
// header file inclusion
#include "mandelbrot.h"

int main(int args, char** agv)
{
    const int rows = 800;
    const int columns = 800;

    float a_min = -2.0;
    float a_max = 1.0;
    float b_min = -1.5;
    float b_max = 1.5;

    // 2d array creation and population
    int** array = create2DArray(rows, columns);
    fill2DArray(array, rows, columns, a_min, a_max, b_min, b_max);

    //unsigned char pixel array
    int fullSize = (rows * columns) * 3;
    unsigned char* pixels = (unsigned char*) malloc(fullSize);

    // populating pixels array, defining rgb
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            int iteration = array[i][j]; // remember i = column, j = row
            unsigned char colors = (unsigned char)(255.0 * iteration/1000);
            int index = (i * columns + j) * 3;
            pixels[index + 0] = colors;
            pixels[index + 1] = colors;
            pixels[index + 2] = colors;
        }
    }

    createImage("mandelbrot.ppm", pixels, columns, rows);
}