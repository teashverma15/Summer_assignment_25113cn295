//Ques 97:Write a program to Merge two sorted arrays.
#include <stdio.h>

void mergeSortedArrays(int arr1[], int n, int arr2[], int m, int merged[]) {
    int i = 0;
    int j = 0; 
    int k = 0; 

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < m) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int mergedSize = n + m;

    int merged[mergedSize];

    mergeSortedArrays(arr1, n, arr2, m, merged);

    printf("Merged Sorted Array:\n");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}