#include<stdio.h>
#include<stdlib.h>
#include "grades.h"
const int num_subjects=6;

int main() 
{
    int num_students=10;
    const char *subject_names[]={"Computer","Physics","Maths","Electrical","Mechanical","EVS"};
    char student_names[num_students][100];
    float marks[num_students][num_subjects][3]; 

    //marks input
    for(int i=0; i<num_students; i++)
    {
        printf("\n\nEnter name of student %d: ",i+1);
        scanf(" %s",student_names[i]);

        printf("Enter details for student %d (3 tests each out of 100):\n",i+1);
        for(int j=0; j<num_subjects; j++) 
        {
            inputMarks(subject_names[j],marks[i][j]);
        }
    }

    //display grade card
    for(int i=0; i<num_students; i++) 
    {
        printf("\nGrade card for %s:\n",student_names[i]);
        for(int j=0; j<num_subjects; j++) 
        {
            printf("\tSubject-%s: ",subject_names[j]);
            for(int k=0; k<3; k++) 
            {
                printf("\n\t\tTest %d - Grade %c ",k+1,calculateGrade(marks[i][j][k]));
            }
            printf("\n");
        }
        float sgpa=calculateSGPA(marks[i],num_subjects);                                           //sgpa
        printf("\nSGPA for %s: %.2f\n",student_names[i],sgpa);
    }

    system("pause");
    return 0;
}