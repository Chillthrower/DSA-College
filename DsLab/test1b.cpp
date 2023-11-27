#include<stdio.h>
#include<stdlib.h>

struct Student
{
    char Name[100];
    int RollNo;
    int marks[3];
};

void EnterDetails(struct Student student[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("enter the sdetails of student : %d\n", (i + 1));
        printf("enter Name : ");
        scanf("%s", &student[i].Name);
        printf("enter RollNo : ");
        scanf("%d", &student[i].RollNo);
        printf("enter subject marks : \n");
        for (int j = 0; j < 3; j++)
        {
            printf("subject : %d\n", (j + 1));
            scanf("%d", &student[i].marks[j]);
        } 
    }
}

void DisplayDetails(struct Student student[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nenter the sdetails of student : %d\n", (i + 1));
        printf("\nentered Name : %s\n", student[i].Name);
        printf("\nentered RollNo : %d\n", student[i].RollNo);
        for (int j = 0; j < 3; j++)
        {
            printf("\nsubject : %d\n", (i + 1));
            printf("%d", student[i].marks[j]);
        } 
    }
}

void TotalMarks(struct Student student[], int n)
{
    printf("student wise total marks\n");
    for (int i = 0; i < n; i++)
    {
        int StduentTotal = 0;
        printf("\nstudent : %d\n", (i + 1));
        for (int j = 0; j < 3; j++)
        {
            printf("\nSubject %d : %d", (j + 1), student[i].marks[j]);
            StduentTotal += student[i].marks[j];
        }
        printf("\nTotal Marks: %d\n\n", StduentTotal);
    }

    printf("subject wise total marks\n");
    for (int i = 0; i < 3; i++)
    {
        int SubjectTotal = 0;
        printf("\nSubject : %d\n", (i + 1));
        for (int j = 0; j < n; j++)
        {
            printf("\nStudent %d : %d", (j + 1), student[j].marks[i]);
            SubjectTotal += student[j].marks[i];
        }
        printf("\nTotal Marks: %d\n\n", SubjectTotal);
    }
    
}

int main()
{
    int n;
    printf("enter the number of students: ");
    scanf("%d", &n);

    struct Student student[n];

    EnterDetails(student, n);
    DisplayDetails(student, n);
    TotalMarks(student, n);

    return 0;
}
