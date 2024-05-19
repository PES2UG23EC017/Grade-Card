#include "grades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void loadData(const char *filename, student **students, int *num_students) 
{
    FILE *file=fopen(filename,"r");
    if(!file) 
    {
        perror("Failed to open file");
        return;
    }

    fscanf(file, "%d", num_students);
    *students=malloc(*num_students * sizeof(student));
    if(*students==NULL) 
    {
        fclose(file);
        return;
    }

    for(int i=0; i<*num_students; i++) 
    {
        fscanf(file, "%s", (*students)[i].name);
        for(int j=0; j<NUM_SUBJECTS; j++) 
        {
            for(int k=0; k<NUM_TESTS; k++) 
            {
                fscanf(file, "%f", &(*students)[i].subjects[j].marks[k]);
            }
        }
    }

    fclose(file);
}

void saveData(const char *filename, student *students, int num_students) 
{
    FILE *file=fopen(filename,"w");
    if(!file) 
    {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "%d\n", num_students);
    for(int i=0; i<num_students; i++) 
    {
        fprintf(file, "%s\n", students[i].name);
        for(int j=0; j<NUM_SUBJECTS; j++) 
        {
            for(int k=0; k<NUM_TESTS; k++) 
            {
                fprintf(file, "%f ", students[i].subjects[j].marks[k]);
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

void searchStudent(student *students, int num_students, const char *name, const char *subject_names[]) 
{
    for(int i=0; i<num_students; i++) 
    {
        if(strcmp(students[i].name,name)==0) 
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
            return;
        }
    }
    printf("Student not found.\n");
}