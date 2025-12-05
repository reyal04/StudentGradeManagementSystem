#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include <vector>
#include "Student.h"

class GradeManager {
private:
    std::vector<Student> students;

public:
    GradeManager() = default;

    void addStudent(const Student& student);
    void displayAllStudents() const;

    bool isEmpty() const { return students.empty(); }
};

#endif
