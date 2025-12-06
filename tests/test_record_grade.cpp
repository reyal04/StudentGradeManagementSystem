#include "../include/Student.h"
#include "../include/GradeManager.h"
#include <cassert>
#include <iostream>

void testRecordGradeNormal() {
    GradeManager gm;
    gm.addStudent(Student(1, "Alice"));

    bool ok = gm.recordGrade(1, "Midterm", 92.0);
    assert(ok);

    const Student* s = gm.findStudentById(1);
    assert(s != nullptr);
    assert(s->getGrades().size() == 1);
    assert(s->getGrades()[0].first == "Midterm");
    assert(s->getGrades()[0].second == 92.0);
    std::cout << "testRecordGradeNormal PASSED\n";
}

void testMultipleGrades() {
    GradeManager gm;
    gm.addStudent(Student(2, "Bob"));

    gm.recordGrade(2, "Quiz1", 80);
    gm.recordGrade(2, "Quiz2", 100);

    const Student* s = gm.findStudentById(2);
    assert(s->getGrades().size() == 2);
    assert(s->getAverage() == 90);
    std::cout << "testMultipleGrades PASSED\n";
}

void testInvalidID() {
    GradeManager gm;
    gm.addStudent(Student(3, "Charlie"));

    bool ok = gm.recordGrade(999, "Final", 75);
    assert(!ok);

    const Student* s = gm.findStudentById(3);
    assert(s->getGrades().empty());
    std::cout << "testInvalidID PASSED\n";
}

int main() {
    testRecordGradeNormal();
    testMultipleGrades();
    testInvalidID();
    std::cout << "All tests PASSED.\n";
    return 0;
}
