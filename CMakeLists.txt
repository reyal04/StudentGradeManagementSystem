cmake_minimum_required(VERSION 3.10)
project(StudentGradeManagementSystem)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Main executable
set(SOURCES
    src/main.cpp
    src/Student.cpp
    src/GradeManager.cpp
)

add_executable(StudentGradeManagementSystem ${SOURCES})

# Tests
enable_testing()
add_executable(test_record_grade tests/test_record_grade.cpp src/Student.cpp src/GradeManager.cpp)
add_test(NAME RecordGradeTests COMMAND test_record_grade)
