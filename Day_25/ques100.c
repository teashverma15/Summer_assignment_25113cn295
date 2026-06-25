//Ques 100:Write a program to Sort words by length. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_length(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    if (len1 < len2) return -1;
    if (len1 > len2) return 1;
    
    return strcmp(str1, str2);
}

int main() {
    char *words[] = {
        "Elephant", 
        "Cat", 
        "Hippopotamus", 
        "Dog", 
        "Giraffe", 
        "Ox"
    };
    
    int num_words = sizeof(words) / sizeof(words[0]);
    
    printf("Original list:\n");
    for (int i = 0; i < num_words; i++) {
        printf("\n%s ", words[i]);
    }
    printf("\n");
    
    qsort(words, num_words, sizeof(char *), compare_length);
    
    printf("Sorted by length (ascending):\n");
    for (int i = 0; i < num_words; i++) {
        printf("\n%s ", words[i]);
    }
    printf("\n");
    
    return 0;
}