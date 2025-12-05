#include "../include/GradeManager.h"
#include <iostream>

void GradeManager::addStudent(const Student& student) {
    students.push_back(student);
}

void GradeManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }

    for (const auto& s : students) {
        s.display();
    }
}
