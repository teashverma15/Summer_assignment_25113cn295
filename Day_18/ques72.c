//Ques 72:Write a program to Sort array in descending order. 
#include<stdio.h>
#include <stdlib.h> 

int compareDescending(const void *a, const void *b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;
   
    return valB - valA; 
}

int main() {
    int arr[] = {23, 78, 13, 5, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, size, sizeof(int), compareDescending);

    printf("Sorted array in descending order: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}