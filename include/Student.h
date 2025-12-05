#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;

public:
    Student();
    Student(int id, const std::string& name);

    int getID() const;
    std::string getName() const;

    void display() const;
};

#endif
