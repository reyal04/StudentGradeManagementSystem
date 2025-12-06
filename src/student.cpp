#include "../include/Student.h"
#include <iostream>

Student::Student() : id(0), name("") {}
Student::Student(int id, const std::string& name) : id(id), name(name) {}

int Student::getID() const { return id; }
std::string Student::getName() const { return name; }

void Student::addGrade(const std::string& assignment, double score) {
    grades.emplace_back(assignment, score);
}

const std::vector<std::pair<std::string,double>>& Student::getGrades() const {
    return grades;
}

double Student::getAverage() const {
    if (grades.empty()) return 0.0;
    double sum = 0.0;
    for (auto &p : grades) sum += p.second;
    return sum / grades.size();
}

void Student::display() const {
    std::cout << "ID: " << id << ", Name: " << name
              << ", Avg: " << getAverage() << "\n";
}
