//Ques 117:Write a program to Create student record system using arrays and strings. 
#include <stdio.h>

struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

int main() {
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n]; 

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf(" %d", &s[i].rollNumber);
        getchar();
        printf("Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\n--- Student Records ---\n");
    for (i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", s[i].rollNumber, s[i].name, s[i].marks);
    }

    return 0;
}