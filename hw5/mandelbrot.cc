#include <cstdio>

// checkBound stays since we only need to worry about changing the mandelbrot function
bool checkBound(float x, float y)
{
    return ((x * x) + (y * y) > 4.0);
}
// combined the xprime/yprime functions into one as per the assignment's orders
void performMandelbrot(float a, float b, float* x, float* y)
{
    // you can dereference x & y to use them in the math of the function
    float realX = *x;
    float realY = *y;

    float xprime = (realX * realX) - (realY * realY) + a;
    float yprime = 2*(realX * realY) + b;

    // ..then turn them back into pointers to be returned
    *x = xprime;
    *y = yprime;
}

// create a 2d array via numerical recipes
int** create2DArray(int a, int b) // a = height, b = width
{
    int** array = new int*[a];
    // allocate flat array
    *array = new int[a * b];
    // setting pointers
    for(int i = 1; i < a; i++)
    {
        array[i] = array[i-1] + b;
    }
    return array;
}

void fill2DArray(int** array, int rows, int columns, float a_min, float a_max, float b_min, float b_max)
{
    float a_step = (a_max - a_min)/(columns-1);
    float b_step = (b_max - b_min)/(rows-1);

    // filling array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            float a = a_min + j * a_step;
            float b = b_min + i * b_step;
            float x = 0;
            float y = 0;
            
            int z;
            for (z = 0; z < 1000; z++)
            {
                performMandelbrot(a, b, &x, &y);
                if(checkBound(x, y))
                {
                    break;
                }
            }
            array[i][j] = z;
        }
    }
}

// modified createimage method from hw4.. a lot was removed since almost every element exists due to the other methods
void createImage(const char* fileName, unsigned char* pixels, int width, int height)
{
    FILE* fp = fopen(fileName, "wb");
    
    // writing header
    fprintf(fp, "P6\n%d %d\n255\n", width, height); // hardcoding is OK since we aren't copying anything over
    // then writing pixel data
    fwrite(pixels, 1, (width*height) * 3, fp);

    fclose(fp);
    printf("ppm image created @%s!\n", fileName);
}