# Final Reflection — Student Grade Management System

## Section 1: Project Summary
**What is your project?**  
Student Grade Management System — a command-line program in C++ to manage students, record grades, and compute averages.

**What features did you implement?**
- Add student (ID + name)
- Display all students
- Record grades per student (assignment name + numeric score)
- Save and load student data to/from a text file (final feature)

**What does your project do well?**
- Clean class separation (Student and GradeManager)
- Simple, robust interactions for adding students and recording grades
- Persists data to a human-readable file format

## Section 2: What Remains
**Unimplemented features from original plan:**
- Sorting students by name or average
- Advanced input validation for assignment names (e.g., duplicate assignment handling)
- A fully automated test suite for all features (I wrote unit tests manually for earlier checkpoints)
- GUI or advanced UI formatting

**Bugs / Issues remaining:**
- File format uses a simple escaping approach; complex characters may need better encoding
- No concurrency or multi-user safety (not required)
- Minimal error messages for malformed files

**What would make the project “complete”:**
- Robust file format (JSON) with round-trip tests
- Full CTest automated coverage for all features
- Sorting, searching, and more polished UI

## Section 3: Time Estimates

| Remaining Item | Time Estimate | Priority |
|----------------|---------------:|:--------:|
| Convert to JSON save/load | 2-3 hours | Nice-to-have |
| Sorting & searching | 1.5-2 hours | Nice-to-have |
| Robust input validation | 1-2 hours | Must-have |
| Full automated tests | 2-3 hours | Must-have |

## Section 4: What I Learned
- Improved understanding of C++ OOP: classes, headers, implementation separation
- Working with STL containers (vector, pair) for grades
- File I/O basics (ifstream/ofstream) and simple serialization
- Writing small test programs and integration testing with CTest

**Hardest part:** deciding on a simple, stable file format and parsing it robustly.

**What I would do differently:** use a JSON library or small homegrown serializer earlier to avoid manual escaping.

## Section 5: Time Log
- Planning and design: 4 hours
- Implementation (features across checkpoints): 12 hours
- Testing and debugging: 5 hours
- Documentation and reflection: 2 hours

