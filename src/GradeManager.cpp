#include "../include/GradeManager.h"
#include <iostream>

int GradeManager::findStudentIndexById(int id) const {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].getID() == id) return static_cast<int>(i);
    }
    return -1;
}

void GradeManager::addStudent(const Student& student) {
    // Prevent duplicate IDs
    if (findStudentIndexById(student.getID()) != -1) {
        std::cerr << "Error: Student with ID " << student.getID() << " already exists.\n";
        return;
    }
    students.push_back(student);
}

bool GradeManager::recordGrade(int id, const std::string& assignment, double score) {
    int idx = findStudentIndexById(id);
    if (idx == -1) return false;
    students[idx].addGrade(assignment, score);
    return true;
}

const Student* GradeManager::findStudentById(int id) const {
    int idx = findStudentIndexById(id);
    if (idx == -1) return nullptr;
    return &students[idx];
}

void GradeManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }
    for (const auto &s : students) s.display();
}

size_t GradeManager::getStudentCount() const {
    return students.size();
}
