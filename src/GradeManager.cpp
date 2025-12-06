#include "../include/GradeManager.h"
#include <iostream>

int GradeManager::findStudentIndexById(int id) const {
    for (int i = 0; i < students.size(); i++)
        if (students[i].getID() == id) return i;
    return -1;
}

void GradeManager::addStudent(const Student& student) {
    if (findStudentIndexById(student.getID()) != -1) {
        std::cerr << "Student already exists.\n";
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
        std::cout << "No students added.\n";
        return;
    }
    for (auto &s : students) s.display();
}

size_t GradeManager::getStudentCount() const {
    return students.size();
}
