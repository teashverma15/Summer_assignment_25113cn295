//Ques 103:Write a program to Create ATM simulation. 
#include <stdio.h>

int main() {
    float balance = 100000.00; 
    int choice;
    float amount;

    while(1) {
        printf("\n   ATM Simulation   \n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Current Balance: $%.2f\n", balance);
                break;
            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                balance += amount;
                printf("Successfully deposited $%.2f\n", amount);
                break;
            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Insufficient funds!\n");
                } else {
                    balance -= amount;
                    printf("Successfully withdrew $%.2f\n", amount);
                }
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}