//Ques 106:Write a program to Create employee management system. 
#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void displayEmployee(struct Employee emp) {
    printf("ID: %d | Name: %s | Salary: %.2f\n", emp.id, emp.name, emp.salary);
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    printf("\n--- Employee Records ---\n");
    for (int i = 0; i < n; i++) {
        displayEmployee(employees[i]);
    }

    return 0;
}