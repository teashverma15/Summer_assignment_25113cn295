//Ques 62:Write a program to Find maximum frequency element. 
#include <stdio.h>

int main() {
    int arr[] = {1, 3, 2, 1, 4, 1, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int max_freq = 0;
    int most_frequent = arr[0];

    for (int i=0;i<n;i++) {
        int count = 0;
        for (int j=0;j<n;j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        
        if (count > max_freq) {
            max_freq = count;
            most_frequent = arr[i];
        }
    }

    printf("Element with maximum frequency: %d\n", most_frequent);
    printf("Frequency: %d\n", max_freq);

    return 0;
}