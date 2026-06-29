//Ques 115:Write a program to Create menu-driven string operations system. 
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int choice;

    while(1) {
        printf("\n--- String Operations Menu ---");
        printf("\n1. Length of String");
        printf("\n2. Concatenate Strings");
        printf("\n3. Compare Strings");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("Length: %zu\n", strlen(str1));
                break;
            case 2:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                strcat(str1, str2);
                printf("Concatenated: %s\n", str1);
                break;
            case 3:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                if (strcmp(str1, str2) == 0) printf("Strings are equal.\n");
                else printf("Strings are not equal.\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}