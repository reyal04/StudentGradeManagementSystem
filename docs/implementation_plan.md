# Implementation Plan

This document details the step-by-step implementation logic for the core features of the Student Grade Management System, based on the `Student` and `GradeManager` class interfaces.

---

## Feature 1: Add New Student

**Trigger**: User selects "Add New Student" from the main menu.

**Input Needed**:
- Student ID (int)
- Student Name (string)

**Implementation Flow**:
1. In `main()`, after the user selects the option:
    - Prompt the user for the Student ID and Name.
    - Call `manager.addStudent(id, name)`.
2. `GradeManager::addStudent(int id, const std::string& name)`:
    - Calls the private helper function `findStudentIndex(id)` to check if the ID already exists.
    - If the ID is found, return `false` (failure) and print an error message.
    - If the ID is not found, create a new `Student` object using the `Student(id, name)` constructor.
    - Push the new `Student` object onto the private `students` vector.
    - Return `true` (success).
3. Back in `main()`:
    - Based on the return value (`true`/`false`), display a success or failure message.
4. Returns to the main menu.

**Data Modified**:
- A new `Student` object is created.
- The `GradeManager::students` vector is modified (size increased).

**Functions Used**:
- `GradeManager::addStudent(int, const std::string&)`
- `GradeManager::findStudentIndex(int)` const
- `Student::Student(int, const std::string&)` (Constructor)

---

## Feature 2: Record Grade

**Trigger**: User selects "Record Grade" from the main menu.

**Input Needed**:
- Student ID (int)
- Assignment Name (string)
- Score (double)

**Implementation Flow**:
1. In `main()`, after the user selects the option:
    - Prompt the user for the Student ID, Assignment Name, and Score.
    - Call `manager.recordGrade(id, assignment, score)`.
2. `GradeManager::recordGrade(int id, const std::string& assignment, double score)`:
    - Calls `manager.getStudent(id)` to get a pointer to the target student.
    - If the student pointer is `nullptr` (ID not found), return `false`.
    - If the student is found, call `studentPtr->addGrade(assignment, score)`.
    - Return `true`.
3. `Student::addGrade(const std::string& assignment, double score)`:
    - Inserts the assignment and score into the private `grades` map. If the assignment already exists, the old score is overwritten.
4. Back in `main()`:
    - Display a success or failure message.
5. Returns to the main menu.

**Data Modified**:
- The `Student::grades` map for the specified student is modified (new entry added or existing entry updated).

**Functions Used**:
- `GradeManager::recordGrade(int, const std::string&, double)`
- `GradeManager::getStudent(int)`
- `Student::addGrade(const std::string&, double)`

---

## Feature 3: Display Student Report (Average Grade)

**Trigger**: User selects "Display Student Report" from the main menu.

**Input Needed**:
- Student ID (int)

**Implementation Flow**:
1. In `main()`, after the user selects the option:
    - Prompt the user for the Student ID.
    - Call `manager.displayStudentReport(id)`.
2. `GradeManager::displayStudentReport(int id)`:
    - Calls `manager.getStudent(id)` to get a pointer to the target student.
    - If the student pointer is `nullptr`, print "Error: Student not found." and return.
    - If found:
        - Call `studentPtr->displayStudentInfo()`.
        - Call `double avg = studentPtr->calculateAverage()`.
        - Print the calculated `avg`.
3. `Student::displayStudentInfo()` const:
    - Prints the student's ID and Name to the console.
    - Loops through the `grades` map and prints each assignment name and score.
4. `Student::calculateAverage()` const:
    - Loops through all scores in the private `grades` map.
    - Calculates the sum of all scores.
    - Divides the sum by the number of grades (map size) and returns the average.
5. Returns to the main menu.

**Data Modified**:
- No permanent data modified (read-only operation).

**Functions Used**:
- `GradeManager::displayStudentReport(int)`
- `GradeManager::getStudent(int)`
- `Student::displayStudentInfo()` const
- `Student::calculateAverage()` const

---

## Feature 4: Save Data to File

**Trigger**: User selects "Save and Quit" from the main menu (or a dedicated "Save Data" option).

**Input Needed**:
- None (filename is stored in `GradeManager::dataFilename`).

**Implementation Flow**:
1. In `main()`, when the quit option is selected:
    - Call `manager.saveToFile()`.
2. `GradeManager::saveToFile() const`:
    - Opens an `ofstream` to `dataFilename`.
    - If the file fails to open, return `false`.
    - Writes the total number of students (`students.size()`) as the first line.
    - Loops through every `Student` object in the `students` vector:
        - Writes the student's ID and Name to the file.
        - Writes the number of grades for that student.
        - Loops through the student's `grades` map (using `student.getGrades()`):
            - Writes the Assignment Name and Score.
    - Closes the file.
    - Returns `true`.
3. Back in `main()`:
    - Display a success or failure message.

**Data Modified**:
- External file (`grades.dat` or similar) is overwritten with the current state of `GradeManager::students`.

**Functions Used**:
- `GradeManager::saveToFile()` const
- `Student::getID()` const
- `Student::getName()` const
- `Student::getGrades()` const
- `GradeManager::getStudentCount()` const


