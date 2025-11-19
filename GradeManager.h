#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include "Student.h" // Must include the class it manages

class GradeManager {
private:
    // Stores all students in the system
    std::vector<Student> students;
    std::string dataFilename; // e.g., "grades.dat"

    // Helper: Finds a student by ID, returns index or -1
    int findStudentIndex(int id) const; 

public:
    // --- Constructor ---
    GradeManager(const std::string& filename);

    // --- Student Management ---
    bool addStudent(int id, const std::string& name);
    Student* getStudent(int id); // Returns pointer for modification
    bool recordGrade(int id, const std::string& assignment, double score);
    
    // --- Display & Calculation ---
    void displayAllStudents() const;
    void displayStudentReport(int id) const;
    
    // --- File I/O ---
    bool saveToFile() const;
    bool loadFromFile();
    
    // --- Utility ---
    int getStudentCount() const;
};

#endif // GRADEMANAGER_H
