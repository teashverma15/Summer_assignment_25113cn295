//Ques 110:Write a program to Create bank account system. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    double balance;
} BankAccount;

void createAccount(BankAccount accounts[], int *totalAccounts);
void depositMoney(BankAccount accounts[], int totalAccounts);
void withdrawMoney(BankAccount accounts[], int totalAccounts);
void checkBalance(BankAccount accounts[], int totalAccounts);
int findAccountIndex(BankAccount accounts[], int totalAccounts, int accNum);

int main() {
    BankAccount accounts[MAX_ACCOUNTS];
    int totalAccounts = 0;
    int choice;

    do 
    {
        printf("\n=================================");
        printf("\n   BANK ACCOUNT MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Create New Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                createAccount(accounts, &totalAccounts);
                break;
            case 2:
                depositMoney(accounts, totalAccounts);
                break;
            case 3:
                withdrawMoney(accounts, totalAccounts);
                break;
            case 4:
                checkBalance(accounts, totalAccounts);
                break;
            case 5:
                printf("\nThank you for using our banking system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 5.\n");
        }
    } 
    while (choice != 5);

    return 0;
}

void createAccount(BankAccount accounts[], int *totalAccounts) 
{
    if (*totalAccounts >= MAX_ACCOUNTS) {
        printf("\nSystem Error: Maximum account registration limit reached!\n");
        return;
    }

    BankAccount newAcc;
    printf("\nEnter 4-digit Account Number: ");
    scanf("%d", &newAcc.accountNumber);

    if (findAccountIndex(accounts, *totalAccounts, newAcc.accountNumber) != -1) {
        printf("Error: An account with number %d already exists.\n", newAcc.accountNumber);
        return;
    }

    printf("Enter Account Holder Name: ");
    while (getchar() != '\n');
    fgets(newAcc.accountHolder, NAME_LENGTH, stdin);
    newAcc.accountHolder[strcspn(newAcc.accountHolder, "\n")] = 0; 

    printf("Enter Initial Deposit Amount: $");
    scanf("%lf", &newAcc.balance);

    if (newAcc.balance < 0) {
        printf("Error: Initial deposit cannot be negative.\n");
        return;
    }

    accounts[*totalAccounts] = newAcc;
    (*totalAccounts)++;

    printf("\nSuccess: Account created successfully for %s!\n", newAcc.accountHolder);
}

void depositMoney(BankAccount accounts[], int totalAccounts) {
    int accNum;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("Error: Account number not found.\n");
        return;
    }

    printf("Enter Amount to Deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be greater than zero.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("\nSuccess: Deposited $%.2f. New Balance: $%.2f\n", amount, accounts[index].balance);
}


void withdrawMoney(BankAccount accounts[], int totalAccounts) {
    int accNum;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("Error: Account number not found.\n");
        return;
    }

    printf("Enter Amount to Withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than zero.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Transaction Denied: Insufficient processing funds!\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("\nSuccess: Withdrew $%.2f. Remaining Balance: $%.2f\n", amount, accounts[index].balance);
}

void checkBalance(BankAccount accounts[], int totalAccounts) {
    int accNum;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accounts, totalAccounts, accNum);
    if (index == -1) {
        printf("Error: Account number not found.\n");
        return;
    }

    printf("\n--- Account Statement ---");
    printf("\nAccount Number : %d", accounts[index].accountNumber);
    printf("\nAccount Holder : %s", accounts[index].accountHolder);
    printf("\nCurrent Balance: $%.2f\n", accounts[index].balance);
}

int findAccountIndex(BankAccount accounts[], int totalAccounts, int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            return i; 
        }
    }
    return -1; 
}