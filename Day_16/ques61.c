//Ques 61:Write a program to Find missing number in array. 
#include<stdio.h>

int findMissingNumber(int arr[], int size) {
    
    int n = size + 1; 
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 4, 5, 3, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int missingNumber = findMissingNumber(arr, size);
    
    printf("The missing number is: %d\n", missingNumber);
    
    return 0;
}