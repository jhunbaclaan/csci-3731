bool checkBound(float x, float y);
void performMandelbrot(float a, float b, float* x, float* y);
int** create2DArray(int a, int b);
void fill2DArray(int** array, int rows, int columns, float a_min, float a_max, float b_min, float b_max);
void createImage(const char* fileName, unsigned char* pixels, int width, int height);