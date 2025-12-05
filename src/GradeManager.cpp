cat > src/GradeManager.cpp <<'EOF'
#include "../include/GradeManager.h"
#include <algorithm>
#include <iostream>

GradeManager::GradeManager() = default;

int GradeManager::findStudentIndexById(int id) const {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].getID() == id) return static_cast<int>(i);
    }
    return -1;
}

void GradeManager::addStudent(const Student& student) {
    // prevent duplicate IDs
    if (findStudentIndexById(student.getID()) != -1) {
        std::cerr << "Error: student ID already exists.\n";
        return;
    }
    students.push_back(student);
}

bool GradeManager::removeStudentById(int id) {
    int idx = findStudentIndexById(id);
    if (idx == -1) return false;
    students.erase(students.begin() + idx);
    return true;
}

Student* GradeManager::findStudentById(int id) {
    int idx = findStudentIndexById(id);
    if (idx == -1) return nullptr;
    return &students[idx];
}

const Student* GradeManager::findStudentByIdConst(int id) const {
    int idx = findStudentIndexById(id);
    if (idx == -1) return nullptr;
    return &students[idx];
}

bool GradeManager::recordGrade(int id, double grade) {
    Student* s = findStudentById(id);
    if (!s) return false;
    s->addGrade(grade);
    return true;
}

bool GradeManager::removeGrade(int id, size_t gradeIndex) {
    Student* s = findStudentById(id);
    if (!s) return false;
    return s->removeGradeAtIndex(gradeIndex);
}

void GradeManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students in gradebook.\n";
        return;
    }
    for (const auto& s : students) s.display();
}

void GradeManager::displayStudent(int id) const {
    const Student* s = findStudentByIdConst(id);
    if (!s) {
        std::cout << "Student not found.\n";
        return;
    }
    s->display();
}

double GradeManager::getClassAverage() const {
    double sum = 0.0;
    int count = 0;
    for (const auto& s : students) {
        double avg = s.getAverage();
        if (!s.getGrades().empty()) { sum += avg; ++count; }
    }
    if (count == 0) return 0.0;
    return sum / count;
}

size_t GradeManager::getStudentCount() const {
    return students.size();
}

bool GradeManager::isEmpty() const {
    return students.empty();
}
EOF
