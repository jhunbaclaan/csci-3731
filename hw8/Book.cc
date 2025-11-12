#include <iostream>
#include "Book.h"

Book::Book() : firstExercise(nullptr), lastExercise(nullptr)
{

}

Book::~Book()
{
    Exercise* current = firstExercise;
    while (current != nullptr)
    {
        Exercise* toRemove = current;
        current = current->getNextExercise();
        delete toRemove;
    }
}

Exercise& Book::addExercise(int chapter, int number)
{
    if (firstExercise == nullptr)
    {
        firstExercise = new Exercise(*this, chapter, number);
        lastExercise = firstExercise;
    }
    else
    {
        Exercise* newExercise = new Exercise(*this, chapter, number, lastExercise);
        lastExercise = newExercise;
    }
    return *lastExercise;
}

Exercise* Book::getExercise(int chapter, int number) const
{
    for(Exercise* current = firstExercise; current != nullptr; current = current->getNextExercise())
    {
        if(current->getChapter() == chapter && current->getNumber() == number)
        {
            return current;
        }
    }
    return nullptr;
}

void Book::printAllExercises() const
{
    Exercise* current = firstExercise;
    bool firstPrinted = false;

    while (current != 0)
    {
        if (current->isAssigned())
        {
            if (firstPrinted)
            {
                std::cout << " ";
            }
            std::cout << current->getChapter() << "." << current->getNumber();
            firstPrinted = true;
        }
        current = current->getNextExercise();
    }
    std::cout << std::endl;
}