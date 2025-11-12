#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>

class Book; // forward declaration

class Exercise
{
    private:
    int chapter;
    int number;
    Exercise* nextExercise; // pointer to the next Exercise
    Book& book;

    // array of pointers
    static const int max = 16; // maximum requirement count
    Exercise* requirements[max];
    int requirementCount;

    // assignment
    bool assigned;

    public:
    Exercise(Book& book, int chapter, int number, Exercise* previous = nullptr);
    // getters
    Exercise* getNextExercise() const;
    int getChapter() const;
    int getNumber() const;
    Book& getBook() const;
    bool isAssigned() const;

    // requirements methods
    void addRequirement(Exercise* required);
    void printRequirements() const;

    // methods for assignment
    void assign();
    void unassign();

    // printing
    void print() const;
    // overload << for printing
    friend std::ostream& operator <<(std::ostream& os, const Exercise& ex);

    friend class Book; // so book can access the private stuff
};

#endif