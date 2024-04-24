#include "grades.h"
#include <stdio.h>

char calculateGrade(float marks) 
{
    if(marks>=90)
        return 'S';
    else if(marks>=80)
        return 'A';
    else if(marks>=70)
        return 'B';
    else if(marks>=60)
        return 'C';
    else if(marks>=50)
        return 'D';
    else if(marks>=40)
        return 'E';
    else
        return 'F';
}

float calculateSGPA(subject subjects[], int num_subjects) 
{
    const int credits[]={5,5,4,4,3,1}; 
    float total_marks=0;
    int total_credits=22;
    
    for(int i=0; i<num_subjects; i++) 
    {
        float subject_total=0;
        for(int j=0; j<NUM_TESTS; j++)
        {
            subject_total+=subjects[i].marks[j];
        }
        float subject_average=subject_total/NUM_TESTS;
        total_marks+=(subject_average/10)*credits[i];
    }
    
    return(total_marks/total_credits);
}

void inputMarks(const char *subject, float marks[]) 
{
    printf("Enter marks for %s:\n",subject);
    for(int i=0; i<NUM_TESTS; i++) 
    {
        printf("Test %d: ",i+1);
        scanf("%f",&marks[i]);
    }
}