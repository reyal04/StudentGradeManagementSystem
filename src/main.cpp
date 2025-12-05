#include <iostream>
#include <limits>
#include <string>
#include "../include/Student.h"
#include "../include/GradeManager.h"

void showMenu() {
    std::cout << "\n=== Student Grade Manager ===\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Record Grade for Student\n";
    std::cout << "3. Display All Students\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    GradeManager manager;
    bool running = true;

    while (running) {
        showMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            int id;
            std::string name;
            std::cout << "Enter student ID: ";
            while (!(std::cin >> id)) {
                std::cout << "Invalid ID. Enter a number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter student name: ";
            std::getline(std::cin, name);

            manager.addStudent(Student(id, name));
            std::cout << "Student added.\n";

        } else if (choice == 2) {
            int id;
            std::string assignment;
            double score;
            std::cout << "Enter student ID: ";
            while (!(std::cin >> id)) {
                std::cout << "Invalid ID. Enter a number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter assignment name: ";
            std::getline(std::cin, assignment);
            std::cout << "Enter score (0-100): ";
            while (!(std::cin >> score)) {
                std::cout << "Invalid score. Enter a number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (manager.recordGrade(id, assignment, score)) {
                std::cout << "Grade recorded.\n";
            } else {
                std::cout << "Student ID not found. Grade not recorded.\n";
            }

        } else if (choice == 3) {
            manager.displayAllStudents();
        } else if (choice == 4) {
            running = false;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
