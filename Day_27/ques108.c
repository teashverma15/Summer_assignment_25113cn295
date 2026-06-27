//Ques 108:Write a program to Create marksheet generation system. 
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NUM_SUBJECTS 3

struct Student {
    int rollNumber;
    char name[50];
    float marks[NUM_SUBJECTS];
    float total;
    float percentage;
    char grade[5];
    char status[10];
};

void calculateResults(struct Student *s);
void displayMarkSheet(const struct Student *s);

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("=========================================\n");
    printf("       MARKSHEET GENERATION SYSTEM       \n");
    printf("=========================================\n");
    
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    if (scanf("%d", &numStudents) != 1 || numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("\n-----------------------------------------\n");
        printf("Entering Details for Student %d\n", i + 1);
        printf("-----------------------------------------\n");
        
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        
        while (getchar() != '\n'); 
        
        printf("Enter Student Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Strip trailing newline

        printf("Enter marks for %d subjects (out of 100):\n", NUM_SUBJECTS);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            do {
                printf("  Subject %d: ", j + 1);
                if (scanf("%f", &students[i].marks[j]) != 1) {
                    printf("  Invalid input. Enter a number.\n");
                    while (getchar() != '\n'); // Clear buffer
                    students[i].marks[j] = -1; // Trigger loop retry
                }
                if (students[i].marks[j] < 0 || students[i].marks[j] > 100) {
                    printf("  Marks must be between 0 and 100. Retry.\n");
                }
            } while (students[i].marks[j] < 0 || students[i].marks[j] > 100);
        }
        calculateResults(&students[i]);
    }

    printf("\n\n=================================================================================\n");
    printf("                               FINAL REPORT CARDS                                \n");
    printf("=================================================================================\n");
    for (int i = 0; i < numStudents; i++) {
        displayMarkSheet(&students[i]);
    }

    return 0;
}

void calculateResults(struct Student *s) {
    s->total = 0;
    int failedASubject = 0;

    for (int j = 0; j < NUM_SUBJECTS; j++) {
        s->total += s->marks[j];
        if (s->marks[j] < 35.0) { 
            failedASubject = 1;
        }
    }

    s->percentage = s->total / NUM_SUBJECTS;

    if (failedASubject) {
        strcpy(s->status, "FAIL");
        strcpy(s->grade, "F");
    } else {
        strcpy(s->status, "PASS");
        if (s->percentage >= 85.0) strcpy(s->grade, "A+");
        else if (s->percentage >= 70.0) strcpy(s->grade, "A");
        else if (s->percentage >= 55.0) strcpy(s->grade, "B");
        else if (s->percentage >= 40.0) strcpy(s->grade, "C");
        else strcpy(s->grade, "D");
    }
}

void displayMarkSheet(const struct Student *s) {
    printf("\n#######################################################\n");
    printf("#                    ACADEMIC RECORD                  #\n");
    printf("#######################################################\n");
    printf(" Roll No: %-10d | Name: %-25s\n", s->rollNumber, s->name);
    printf("-------------------------------------------------------\n");
    printf(" Subject Code       | Maximum Marks    | Obtained Marks\n");
    printf("-------------------------------------------------------\n");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf(" Subject %-11d| 100              | %.2f\n", j + 1, s->marks[j]);
    }
    printf("-------------------------------------------------------\n");
    printf(" GRAND TOTAL: %.2f / %d\n", s->total, NUM_SUBJECTS * 100);
    printf(" PERCENTAGE:  %.2f%%\n", s->percentage);
    printf(" GRADE:       %s\n", s->grade);
    printf(" STATUS:      %s\n", s->status);
    printf("#######################################################\n");
}