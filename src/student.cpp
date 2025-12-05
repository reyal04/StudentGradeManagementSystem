cat > src/Student.cpp <<'EOF'
#include "../include/Student.h"
#include <numeric>

Student::Student()
    : id(0), name("") {}

Student::Student(int studentID, const std::string& studentName)
    : id(studentID), name(studentName) {}

int Student::getID() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

std::vector<double> Student::getGrades() const {
    return grades;
}

void Student::setName(const std::string& newName) {
    name = newName;
}

void Student::addGrade(double grade) {
    grades.push_back(grade);
}

bool Student::removeGradeAtIndex(size_t index) {
    if (index >= grades.size()) return false;
    grades.erase(grades.begin() + index);
    return true;
}

double Student::getAverage() const {
    if (grades.empty()) return 0.0;
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}

void Student::display() const {
    std::cout << "ID: " << id << " | Name: " << name << " | Avg: " << getAverage() << std::endl;
    if (!grades.empty()) {
        std::cout << "Grades: ";
        for (double g : grades) std::cout << g << " ";
        std::cout << std::endl;
    }
}
EOF
