//Ques 57:Write a program to Reverse array. 
#include<stdio.h>

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    while (start<end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void printArray(int arr[], int size) {
    for (int i=0;i<size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    if (scanf("%d",&size)!= 1||size<=0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i=0;i<size;i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    printArray(arr, size);

    reverseArray(arr, size);

    printf("Reversed array: ");
    printArray(arr, size);

    return 0;
}