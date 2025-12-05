#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include <vector>
#include <string>
#include "Student.h"

class GradeManager {
private:
    std::vector<Student> students;
    int findStudentIndexById(int id) const;

public:
    GradeManager() = default;

    // Student management
    void addStudent(const Student& student);
    bool recordGrade(int id, const std::string& assignment, double score);
    const Student* findStudentById(int id) const;

    // Display
    void displayAllStudents() const;
    size_t getStudentCount() const;
};

#endif // GRADEMANAGER_H
