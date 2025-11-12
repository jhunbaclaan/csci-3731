#include <iostream>
#include "Exercise.h"
#include "Book.h"

int main()
{
    Book book;

    // make exercises
    Exercise& ex1_1 = book.addExercise(1, 1);
    Exercise& ex1_2 = book.addExercise(1, 2);
    Exercise& ex2_1 = book.addExercise(2, 1);
    Exercise& ex2_2 = book.addExercise(2, 2);
    Exercise& ex3_1 = book.addExercise(3, 1);
    Exercise& ex3_2 = book.addExercise(3, 2);

    // requirements
    // very generic list, probably shouldve used the assignments from the book But I Got Lazy Bruhhhhhhhh
    ex2_1.addRequirement(&ex1_1);
    ex2_2.addRequirement(&ex1_2);
    ex3_1.addRequirement(&ex2_1);
    ex3_2.addRequirement(&ex2_2);

    // loop for assignment/unassignment
    std::cout << "use + to assign assignments, and - to unassign them.\n";
    std::cout << "e.g.: 1.1 or -1.1.\n";
    std::cout << "enter 0 to quit the program.\n";

    while (true)
    {
        int chap, num;
        char dot;

        std::cout << "enter exercises: ";
        std::cin >> chap;
        if (chap == 0)
        {
            break;
        }
        std::cin >> dot >> num; // dot + number

        Exercise* ex = book.getExercise(std::abs(chap), num);
        if (ex == nullptr)
        {
            std::cout << "exercise not found..\n";
            continue;
        }
        if (chap > 0) // positive
        {
            ex->assign();
            std::cout << "exercise " << *ex << " has been assigned." << std::endl;
        }
        else
        {
            ex->unassign();
            std::cout << "exercise " << *ex << " has been unassigned." << std::endl;
        }
        std::cout << "current book: ";
        book.printAllExercises();
    }

    std::cout << "program ending. thanks!";
    return 0;
}