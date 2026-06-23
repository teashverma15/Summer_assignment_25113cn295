//Ques 92:Write a program to Find maximum occurring character.
#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

int main() {
    char str[100];
    int count[ASCII_SIZE] = {0};
    int max = -1; 
    char result;

    printf("Enter a string: ");
    gets(str);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        count[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < len; i++) {
        if (max < count[(unsigned char)str[i]]) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }

    printf("Maximum occurring character is '%c', appearing %d times.\n", result, max);

    return 0;
}