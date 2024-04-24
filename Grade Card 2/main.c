#include <stdio.h>
#include <stdlib.h>
#include "grades.h"

int main() 
{
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d",&num_students);

    student *students=malloc(num_students*sizeof(student));                                 //memory allocation
    if(students==NULL)
    {
        return 1;
    }

    const char *subject_names[NUM_SUBJECTS]={"Computer","Physics","Maths","Electrical","Mechanical","EVS"};

    for(int i=0; i<num_students; i++) 
    {
        printf("\n\nEnter name of student %d: ",i+1);
        scanf("%s",students[i].name);

        printf("Enter details for student %d (3 tests each out of 100):\n",i+1);
        for(int j=0; j<NUM_SUBJECTS; j++) 
        {
            inputMarks(subject_names[j],students[i].subjects[j].marks);
        }
    }

//sgpa
    for(int i=0; i<num_students; i++) 
    {
        float total_sgpa=0;
        for(int j=0; j<NUM_SUBJECTS; j++) 
        {
            float sgpa=calculateSGPA(students[i].subjects,NUM_SUBJECTS);
            students[i].sgpa=sgpa;
            total_sgpa+=sgpa;
        }
        students[i].sgpa=total_sgpa/NUM_SUBJECTS;
    }

//grade card
    for(int i=0; i<num_students; i++) 
    {
        printf("\nGrade card for %s:\n",students[i].name);
        for(int j=0; j<NUM_SUBJECTS; j++) 
        {
            printf("\tSubject-%s: ",subject_names[j]);
            for(int k=0; k<NUM_TESTS; k++) 
            {
                printf("\n\t\tTest %d - Grade %c ",k+1,calculateGrade(students[i].subjects[j].marks[k]));
            }
            printf("\n");
        }
        printf("\nSGPA for %s: %.2f\n",students[i].name,students[i].sgpa);
    }

    free(students);                                             //free memory

    return 0;
}
