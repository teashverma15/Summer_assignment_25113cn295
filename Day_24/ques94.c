//Ques 94:Write a program to Compress a string. 
#include <stdio.h>
#include <string.h>

void compressString(const char *src, char *dest) {
    int i = 0;
    int j = 0;
    int len = strlen(src);

    while (i < len) {
        int count = 1;
        
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }

        dest[j++] = src[i];
        j += sprintf(&dest[j], "%d", count);

        i++;
    }
    
    dest[j] = '\0';
}

int main() {
    char original[] = "AAABBBCCDAA";
    char compressed[2 * sizeof(original)]; 

    compressString(original, compressed);

    printf("Original string:   %s\n", original);
    printf("Compressed string: %s\n", compressed);

    return 0;
}