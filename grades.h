#ifndef GRADES_H
#define GRADES_H

extern const int num_subjects;

void inputMarks(const char *subject, float marks[]);
char calculateGrade(float marks);
float calculateSGPA(float marks[][3],int num_subjects);

#endif
