#ifndef IMAGEMAKER_H
#define IMAGEMAKER_H

class imageMaker{
    private:
        const char fileName;
        int width = 0;
        int height = 0;

    public:
        imageMaker(const char* fileName, int width, int height);
        virtual ~imageMaker();

        unsigned char* readPPM(const char* fileName) const;
        void makePPM(const char* fileName, unsigned char* pixels, int width, int height) const;
};

#endif