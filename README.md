# Student Grade Management System
A command-line program for adding students, recording grades, and calculating averages.

## Features
- Add new students
- Remove existing students
- Enter and store grades for each student
- View individual student information (ID, name, average)
- Calculate class average

## Building
Create a build directory and compile using CMake:

```bash
mkdir build
cd build
cmake ..
cmake --build .

mkdir -p build
cd build
cmake ..
cmake --build .

# Run the program
./StudentGradeManagementSystem

# Run tests (if you wrote them manually and wired them to CMake)
ctest --verbose

