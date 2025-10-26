bool isPPM(const char* fileName);
unsigned char* readPPM(const char* fileName, int* width, int* height);
void createImage(const char* fileName, unsigned char* img, int width, int height, int quality);