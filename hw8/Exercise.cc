#include <iostream>
#include "Exercise.h"
#include "Book.h"

Exercise::Exercise(Book& book, int chapter, int number, Exercise* previous)
    : chapter(chapter), number(number), nextExercise(nullptr), book(book), requirementCount(0), assigned(false)
{
    // setup the linked list; if previous node exists, link it to current
    if (previous != nullptr)
    {
        previous->nextExercise = this;
    }

    // requirements array 
    for (int i = 0; i < max; ++i)
    {
        requirements[i] = 0;
    }
}

// getters
Exercise* Exercise::getNextExercise() const
{
    return nextExercise;
}
int Exercise::getChapter() const
{
    return chapter;
}
int Exercise::getNumber() const
{
    return number;
}
Book& Exercise::getBook() const
{
    return book;
}
bool Exercise::isAssigned() const
{
    return assigned;
}

// requirements
void Exercise::addRequirement(Exercise* req)
{
    if (req == nullptr)
    {
        return;
    }
    if (requirementCount < max)
    {
        requirements[requirementCount++] = req;
    }
    else
    {
        std::cerr << "max requirement count reached.\n";
    }
}

void Exercise::printRequirements() const
{
    if (requirementCount == 0)
    {
        std::cout << "no requirements needed";
        return;
    }

    for (int i = 0; i < requirementCount; ++i)
    {
        if (requirements[i] != 0)
        {
            std::cout << requirements[i]->chapter << "." << requirements[i]->number;
            if (i < requirementCount - 1)
            {
                std::cout << ", ";
            }
        }
    }
}

// assign/unassign
void Exercise::assign()
{
    if (assigned)
    {
        return;
    }
    assigned = true;

    // recursive assign
    for (int i = 0; i < requirementCount; ++i)
    {
        if (requirements[i] != 0)
        {
            requirements[i]->assign();
        }
    }
}
void Exercise::unassign()
{
    if (!assigned)
    {
        return;
    }
    assigned = false;

    // recursive unassign
    for (Exercise* current = book.firstExercise; current != nullptr; current = current->nextExercise)
    {
        for (int i = 0; i < current->requirementCount; ++i)
        {
            if (current->requirements[i] == this)
            {
                current->unassign();
                break;
            } 
        }
    }
}

// printing
void Exercise::print() const
{
    if (assigned)
    {
        std::cout << chapter << "." << number;
    }
    else
    {
        std::cout << "*.*"; // placeholder print for non-assigned stuffs
    }
}
// overload << for printing
std::ostream& operator <<(std::ostream& os, const Exercise& ex)
{
    if (ex.assigned)
    {
        os << ex.chapter << "." << ex.number;
    }
    else
    {
        os << "*.*";
    }
    return os;
}