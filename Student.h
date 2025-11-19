#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map> 
#include <iostream>

/**
* Student class represents a single student with a unique ID,
* name, and a collection of grades for different assignments.
*/
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
    // Use const reference to avoid copying the whole map when retrieving
    const std::map<std::string, double>& getGrades() const; 
    
    // --- Core Functionality ---
    void addGrade(const std::string& assignment, double score);
    double calculateAverage() const;
    
    // Display
    void displayStudentInfo() const;
};

#endif // STUDENT_H
