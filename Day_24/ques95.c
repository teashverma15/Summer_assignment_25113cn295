//Ques 95:Write a program to Find longest word. 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[200];
    char largest_word[50] = "";
    char current_word[50] = "";
    
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    while (sentence[i] != '\0') {
        if (!isspace((unsigned char)sentence[i]) && sentence[i] != '\0') {
            current_word[j] = sentence[i];
            j++;
        } else {
        
            if (j > 0) {
                current_word[j] = '\0';

                if (strlen(current_word) > strlen(largest_word)) {
                    strcpy(largest_word, current_word);
                }
                j = 0; 
            }
        }
        i++;
    }
    if (j > 0) {
        current_word[j] = '\0';
        if (strlen(current_word) > strlen(largest_word)) {
            strcpy(largest_word, current_word);
        }
    }

    if (strlen(largest_word) > 0) {
        printf("\nThe largest word is: %s\n", largest_word);
        
    } else {
        printf("\nNo valid word found.\n");
    }

    return 0;
}