//Ques 119:Write a program to Create mini employee management system. 
#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for(i = 0; i < n; i++) {
        printf("\nDetails for Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    printf("\n--- Employee Management System ---\n");
    printf("ID\tName\t\tSalary\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }

    return 0;
}