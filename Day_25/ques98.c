//Ques 98:Write a program to Find common characters in strings. 
#include <stdio.h>
#include <string.h>

void findCommonChars(char str1[], char str2[]) {
    int presentInStr1[256] = {0};
    int alreadyPrinted[256] = {0};
    int found = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        presentInStr1[(unsigned char)str1[i]] = 1;
    }

    printf("Common characters: ");

    for (int i = 0; str2[i] != '\0'; i++) {
        unsigned char ch = str2[i];
        
        if (presentInStr1[ch] && !alreadyPrinted[ch]) {
            printf("%c ", ch);
            alreadyPrinted[ch] = 1;
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[] = "programming";
    char str2[] = "computer";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    
    findCommonChars(str1, str2);

    return 0;
}