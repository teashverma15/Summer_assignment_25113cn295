//Ques 90:Write a program to Find first repeating character.
#include<stdio.h>
int main()
{
    char str[100];
    int i, j;
    int repeating;
    char result = '\0';

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        repeating = 0;
        for (j = 0; str[j] != '\0'; j++) {
            if (str[i] == str[j] && i != j) {
                repeating = 1; 
                break;           
            }
        }

        if (repeating == 1) {
            result = str[i];
            break; 
        }
    }

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("All characters are non-repeating or the string is empty.\n");
    }

    return 0;
}