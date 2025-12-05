cat > tests/test_add_student.cpp <<'EOF'
#include "../include/Student.h"
#include "../include/GradeManager.h"
#include <cassert>
#include <iostream>

void testAddStudent() {
    GradeManager gm;
    Student s(1, "Alice");
    gm.addStudent(s);
    assert(gm.getStudentCount() == 1);
    std::cout << "testAddStudent PASSED\n";
}

void testDefaultStudent() {
    Student s;
    assert(s.getID() == 0);
    assert(s.getName() == "");
    std::cout << "testDefaultStudent PASSED\n";
}

void testRecordGrade() {
    GradeManager gm;
    Student s(2, "Bob");
    gm.addStudent(s);
    bool ok = gm.recordGrade(2, 95.0);
    assert(ok);
    const Student* sp = gm.findStudentByIdConst(2);
    assert(sp != nullptr);
    assert(sp->getGrades().size() == 1);
    std::cout << "testRecordGrade PASSED\n";
}

int main() {
    testAddStudent();
    testDefaultStudent();
    testRecordGrade();
    std::cout << "All tests passed.\n";
    return 0;
}
EOF
