//Ques 84:Write a program to Convert lowercase to uppercase.
 #include <stdio.h>
#include <ctype.h>

int main() {
    char str[]="hello world";
    int vowels = 0, consonants = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = toupper((unsigned char)str[i]);
    }

    printf("Upercase string:%s",str);

    return 0;
}
