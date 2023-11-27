#include <stdio.h>

struct Student 
{
    int rollNo;
    char name[50];
    int semester;
    int marks[3];
};

void enterDetails(struct Student students[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Semester: ");
        scanf("%d", &students[i].semester);

        printf("Enter marks in 3 subjects:\n");
        for (int j = 0; j < 3; j++) 
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }
}

void displayDetails(struct Student *students, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Semester: %d\n", students[i].semester);
        printf("Marks in 3 subjects: %d, %d, %d\n\n",students[i].marks[0], students[i].marks[1], students[i].marks[2]);
    }
}

void calculateTotals(struct Student *students, int n) 
{
    printf("\nStudent-wise and Subject-wise Total Marks:\n");
    for (int i = 0; i < n; i++) 
    {
        int studentTotal = 0;
        printf("Student %d:\n", i + 1);
        for (int j = 0; j < 3; j++) 
        {
            printf("Subject %d: %d\n", j + 1, students[i].marks[j]);
            studentTotal += students[i].marks[j];
        }
        printf("Total Marks: %d\n\n", studentTotal);
    }

    printf("Subject-wise Total Marks:\n");
    for (int j = 0; j < 3; j++) 
    {
        int subjectTotal = 0;
        printf("Subject %d:\n", j + 1);
        for (int i = 0; i < n; i++) 
        {
            printf("Student %d: %d\n", i + 1, students[i].marks[j]);
            subjectTotal += students[i].marks[j];
        }
        printf("Total Marks: %d\n\n", subjectTotal);
    }
}

int main() 
{
    struct Student students[1];

    enterDetails(students, 1);

    printf("\nDetails of 2 students:\n");
    displayDetails(students, 1);

    calculateTotals(students, 1);

    return 0;
}
