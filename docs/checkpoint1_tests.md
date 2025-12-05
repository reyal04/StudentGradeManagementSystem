cat > docs/checkpoint1_tests.md <<'EOF'
# Checkpoint 1 Test Cases

## Feature: Add Student

### Test 1: Add Student Normally
- Input: Student(1, "Alice")
- Expected: getStudentCount() == 1
- Result: PASS

### Test 2: Default Student
- Input: Student()
- Expected: ID == 0, name == ""
- Result: PASS

### Test 3: Record Grade
- Steps: add Student(2,"Bob"), recordGrade(2,95.0)
- Expected: recordGrade returns true and student has 1 grade
- Result: PASS
EOF

cat > docs/checkpoint1_reflection.md <<'EOF'
# Checkpoint 1 Reflection

## What I Implemented
Implemented "Add Student" feature: Student class implementation, GradeManager basic functions, display.

## Challenges
- Setting up CMake and ensuring include paths were correct.
- Writing tests using CTest for the first time.

## What I Learned
- Linking header and source files, using vectors, basic unit tests with CTest.

## Time Spent
Approximately 2-3 hours.
EOF
