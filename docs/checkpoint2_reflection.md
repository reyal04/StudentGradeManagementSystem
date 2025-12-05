# Checkpoint 2 Reflection - Record Grade

## What I implemented
- Added the ability to record an assignment name and numeric score for a student.
- Student stores a vector of (assignment,score), and calculates average.
- GradeManager supports recording grades and retrieving students.
- main.cpp menu updated with "Record Grade" option.

## Integration with Feature 1
- Uses Student objects created in Feature 1.
- Adds grade metadata to the same object and displays updated averages.

## Challenges
- Designing a simple representation for assignment+score (chose vector<pair<string,double>>).
- Input validation for numeric fields.

## Testing
- Wrote 3 tests covering normal, multi-grade, and invalid ID cases. All passed during local testing.

## Time spent
~2.5 hours
