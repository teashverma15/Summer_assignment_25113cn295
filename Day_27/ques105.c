//Ques 105:Write a program to Create student record management system. 
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

void addRecord() {
    FILE *fp = fopen("students.txt", "a");
    struct Student s;

    printf("Enter ID, Name, and GPA: ");
    scanf("%d %s %f", &s.id, s.name, &s.gpa);

    fprintf(fp, "%d %s %.2f\n", s.id, s.name, s.gpa);
    fclose(fp);
    printf("Record added successfully!\n");
}

void displayRecords() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;

    printf("\n Student Records \n");
    while (fscanf(fp, "%d %s %f", &s.id, s.name, &s.gpa) != EOF) {
        printf("ID: %d | Name: %s | GPA: %.2f\n", s.id, s.name, s.gpa);
    }
    fclose(fp);
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Add Record\n2. Display Records\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addRecord();
        else if (choice == 2) displayRecords();
        else break;
    }
    return 0;
}