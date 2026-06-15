//Ques 58:Write a program to Rotate array left. 
#include <stdio.h>

void rotateLeft(int arr[], int size) {
    if (size <= 1) return;
    
    int temp = arr[0];
    
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    arr[size - 1] = temp;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    rotateLeft(arr, size);

    printf("Rotated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}