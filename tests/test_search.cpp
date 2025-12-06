#include <cassert>
#include <iostream>
#include "../include/GradeManager.h"

// A simple manual test for searching for a student
void test_search_student() {
    GradeManager gm;

    // Add some students
    gm.addStudent("001", "Alice");
    gm.addStudent("002", "Bob");
    gm.addStudent("003", "Charlie");

    // Test existing student search
    Student* s1 = gm.searchStudent("002");
    assert(s1 != nullptr);
    assert(s1->getId() == "002");
    assert(s1->getName() == "Bob");

    // Test missing student search
    Student* s2 = gm.searchStudent("999");
    assert(s2 == nullptr);

    std::cout << "test_search_student passed!" << std::endl;
}

int main() {
    test_search_student();
    std::cout << "All search tests passed!" << std::endl;
    return 0;
}
