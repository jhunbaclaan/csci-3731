#ifndef IMAGEMAKER_H
#define IMAGEMAKER_H

class imageMaker{
    private:
        const char* fileName;
        int width;
        int height;
        unsigned char* pixels;

    public:
        imageMaker(const char* fileName); 
        virtual ~imageMaker();

        unsigned char* readPPM(const char* fileName);
        void makePPM(const char* fileName) const;
        void operator+=(int value); // for overloading
};

#endif