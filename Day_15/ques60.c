//Ques 60:Write a program to Move zeroes to end.
#include <stdio.h>

void moveZeroes(int arr[], int n) {
    int count = 0; 

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    while (count < n) {
        arr[count++] = 0;
    }
}

int main() {
    int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, n);

    printf("Array after moving zeroes to end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}