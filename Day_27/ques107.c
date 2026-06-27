//Ques 107:Write a program to Create salary management system.
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra;         
    float da;        
    float pf;         
    float gross_salary;
    float net_salary;
};

void addEmployee(struct Employee emp[], int *count);
void displayAllEmployees(struct Employee emp[], int count);
void generatePayslip(struct Employee emp[], int count);
void calculateSalary(struct Employee *emp);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM     ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Employee Salaries");
        printf("\n3. Search & Generate Payslip");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &employee_count);
                break;
            case 2:
                displayAllEmployees(employees, employee_count);
                break;
            case 3:
                generatePayslip(employees, employee_count);
                break;
            case 4:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

void calculateSalary(struct Employee *emp) {
    emp->hra = emp->basic_salary * 0.15; // 15% HRA
    emp->da = emp->basic_salary * 0.10;  // 10% DA
    emp->pf = emp->basic_salary * 0.12;  // 12% PF Deduction
    
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    
    emp->net_salary = emp->gross_salary - emp->pf;
}

void addEmployee(struct Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: System database is full!\n");
        return;
    }

    struct Employee new_emp;
    
    printf("\nEnter Employee ID (Integer): ");
    scanf("%d", &new_emp.id);
    
    getchar(); 
    
    printf("Enter Employee Name: ");
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = '\0';
    
    printf("Enter Basic Salary: ");
    scanf("%f", &new_emp.basic_salary);

    calculateSalary(&new_emp);

    emp[*count] = new_emp;
    (*count)++;
    
    printf("\nEmployee record added successfully!\n");
}

void displayAllEmployees(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records found! Please add employees first.\n");
        return;
    }

    printf("\n========================================================================================\n");
    printf("%-5s %-20s %-12s %-10s %-10s %-10s %-12s\n", "ID", "Name", "Basic", "HRA", "DA", "PF (Ded)", "Net Salary");
    printf("========================================================================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-12.2f %-10.2f %-10.2f %-10.2f %-12.2f\n", 
               emp[i].id, emp[i].name, emp[i].basic_salary, 
               emp[i].hra, emp[i].da, emp[i].pf, emp[i].net_salary);
    }
    printf("========================================================================================\n");
}

void generatePayslip(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    int search_id;
    int found = 0;
    
    printf("\nEnter Employee ID to look up: ");
    scanf("%d", &search_id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == search_id) {
            found = 1;
            printf("\n-------------------------------------------");
            printf("\n             SALARY PAYSLIP                ");
            printf("\n-------------------------------------------");
            printf("\nEmployee ID   : %d", emp[i].id);
            printf("\nEmployee Name : %s", emp[i].name);
            printf("\n-------------------------------------------");
            printf("\nEARNINGS:");
            printf("\n  Basic Salary: $%.2f", emp[i].basic_salary);
            printf("\n  HRA (15%%)   : $%.2f", emp[i].hra);
            printf("\n  DA (10%%)    : $%.2f", emp[i].da);
            printf("\n  GROSS SALARY: $%.2f", emp[i].gross_salary);
            printf("\n-------------------------------------------");
            printf("\nDEDUCTIONS:");
            printf("\n  PF (12%%)    : $%.2f", emp[i].pf);
            printf("\n-------------------------------------------");
            printf("\nNET TAKE-HOME : $%.2f", emp[i].net_salary);
            printf("\n-------------------------------------------\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }
}
