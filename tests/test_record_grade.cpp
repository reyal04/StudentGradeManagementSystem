#include "../include/Student.h"
#include "../include/GradeManager.h"
#include <cassert>
#include <iostream>

/*
 * TEST 1 — Normal Case:
 * Add a student, record one grade, verify grade & average.
 */
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
    assert(s->getAverage() == 92.0);

    std::cout << "testRecordGradeNormal PASSED\n";
}

/*
 * TEST 2 — Multiple Grades:
 * Add two grades, verify average is correct.
 */
void testRecordMultipleGrades() {
    GradeManager gm;
    gm.addStudent(Student(2, "Bob"));

    gm.recordGrade(2, "Quiz1", 80);
    gm.recordGrade(2, "Quiz2", 100);

    const Student* s = gm.findStudentById(2);
    assert(s != nullptr);

    assert(s->getGrades().size() == 2);

    double avg = s->getAverage();
    assert(avg == (80 + 100) / 2.0);

    std::cout << "testRecordMultipleGrades PASSED\n";
}

/*
 * TEST 3 — Invalid ID:
 * Try to record a grade for a student that does not exist.
 */
void testRecordGradeInvalidID() {
    GradeManager gm;
    gm.addStudent(Student(3, "Charlie"));

    bool ok = gm.recordGrade(999, "Final", 75.0);
    assert(!ok); // Should fail

    const Student* s = gm.findStudentById(3);
    assert(s->getGrades().empty());

    std::cout << "testRecordGradeInvalidID PASSED\n";
}

int main() {
    testRecordGradeNormal();
    testRecordMultipleGrades();
    testRecordGradeInvalidID();

    std::cout << "All tests PASSED.\n";
    return 0;
}
