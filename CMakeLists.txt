cat > CMakeLists.txt <<'EOF'
cmake_minimum_required(VERSION 3.10)
project(StudentGradeManagementSystem)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Student.cpp
    src/GradeManager.cpp
)

add_executable(StudentGradeManagementSystem \${SOURCES})

# Testing
enable_testing()
add_executable(test_add_student tests/test_add_student.cpp src/Student.cpp src/GradeManager.cpp)
add_test(NAME AddStudentTest COMMAND test_add_student)
EOF

