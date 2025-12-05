cat > src/main.cpp <<'EOF'
#include <iostream>
#include <string>
#include "../include/Student.h"
#include "../include/GradeManager.h"

int main() {
    GradeManager manager;

    std::cout << "=== Student Grade Manager (Checkpoint 1: Add Student) ===\n";

    int id;
    std::string name;
    std::cout << "Enter student ID: ";
    while (!(std::cin >> id)) {
        std::cout << "Invalid input. Enter numeric ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    Student s(id, name);
    manager.addStudent(s);

    std::cout << "Student added successfully.\n";
    std::cout << "Current students:\n";
    manager.displayAllStudents();

    return 0;
}
EOF
