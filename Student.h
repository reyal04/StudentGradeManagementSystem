#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map> // To store grades: e.g., <AssignmentName, Score>
#include <iostream>

class Student {
private:
    int studentID;
    std::string name;
    // Maps assignment/course name to the grade/score (e.g., "Midterm", 85.5)
    std::map<std::string, double> grades;

public:
    // --- Constructors ---
    Student();
    Student(int id, const std::string& n);

    // --- Getters (const methods) ---
    int getID() const;
    std::string getName() const;
    const std::map<std::string, double>& getGrades() const;
    
    // --- Core Functionality ---
    void addGrade(const std::string& assignment, double score);
    double calculateAverage() const;
    
    // Display
    void displayStudentInfo() const;
};

#endif // STUDENT_H
