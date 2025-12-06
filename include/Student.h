#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <utility>

class Student {
private:
    int id;
    std::string name;
    std::vector<std::pair<std::string,double>> grades;

public:
    Student();
    Student(int id, const std::string& name);

    int getID() const;
    std::string getName() const;

    void addGrade(const std::string& assignment, double score);
    const std::vector<std::pair<std::string,double>>& getGrades() const;
    double getAverage() const;

    void display() const;
};

#endif
