#include "../include/Student.h"
#include "../include/GradeManager.h"
#include <cassert>
#include <iostream>

void testRecordGradeNormal() {
    GradeManager gm;
    Student s(1, "Alice");
    gm.addStudent(s);
    bool ok = gm.recordGrade(1, "Midterm", 90.0);
    assert(ok);
    const Student* sp = gm.findStudentById(1);
    assert(sp != nullptr);
    assert(sp->getGrades().size() == 1);
    assert(sp->getAverage() == 90.0);
    std::cout << "testRecordGradeNormal PASSED\n";
}

void testRecordMultipleGrades() {
    GradeManager gm;
    gm.addStudent(Student(2, "Bob"));
    gm.recordGrade(2, "Q1", 80.0);
    gm.recordGrade(2, "Q2", 100.0);
    const Student* sp = gm.findStudentById(2);
    assert(sp != nullptr);
    assert(sp->getGrades().size() == 2);
    double avg = sp->getAverage();
    assert(avg == (80.0 + 100.0) / 2.0);
    std::cout << "testRecordMultipleGrades PASSED\n";
}

void testRecordGradeInvalidID() {
    GradeManager gm;
    gm.addStudent(Student(3, "Carol"));
    bool ok = gm.recordGrade(999, "Midterm", 75.0);
    assert(!ok); // invalid id should return false
    std::cout << "testRecordGradeInvalidID PASSED\n";
}

int main() {
    testRecordGradeNormal();
    testRecordMultipleGrades();
    testRecordGradeInvalidID();
    std::cout << "All tests passed.\n";
    return 0;
}
