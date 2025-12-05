#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <utility> // for std::pair

class Student {
private:
    int id;
    std::string name;
    // list of (assignmentName, score)
    std::vector<std::pair<std::string, double>> grades;

public:
    Student();
    Student(int id, const std::string& name);

    // Basic getters
    int getID() const;
    std::string getName() const;

    // Grade operations
    void addGrade(const std::string& assignment, double score);
    const std::vector<std::pair<std::string,double>>& getGrades() const;
    double getAverage() const;

    // Display
    void display() const;
};

#endif // STUDENT_H
