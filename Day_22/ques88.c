//Ques 88:Write a program to Remove spaces from string.
#include <stdio.h>

void removeSpaces(char *str) {
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

int main() {
    char str[] = "Hello World ";
    
    printf("Original: %s\n", str);
    removeSpaces(str);
    printf("Modified: %s\n", str);

    return 0;
}