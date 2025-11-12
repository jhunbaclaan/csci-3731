#ifndef BOOK_H
#define BOOK_H
#include "Exercise.h"

class Book
{
    private:
        Exercise* firstExercise;
        Exercise* lastExercise;

        // implement rule of 5
        Book(const Book&);
        Book& operator=(const Book&);
    public:
        Book();
        virtual ~Book();

        Exercise& addExercise(int chapter, int number);
        Exercise* getExercise(int chapter, int number) const;
        void printAllExercises() const;

        friend class Exercise; // friend to access book's private stuff
};

#endif