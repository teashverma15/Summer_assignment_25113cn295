//Ques 55:Write a program to Second largest element. 
#include <stdio.h>
#include <limits.h> 

int findSecondLargest(int arr[], int size);

int main() {
    int i, n;
    printf("Enter the number of array: ");
    scanf("%d",&n);
    printf("\n Enter %d elements:\n", n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findSecondLargest(arr, size);

    if (result == -1) {
        printf("There is no distinct second largest element.\n");
    } else {
        printf("The second largest element is: %d\n", result);
    }

    return 0;
}

int findSecondLargest(int arr[], int size) {

    if (size < 2) {
        printf("Invalid Input: Array must contain at least 2 elements.\n");
        return -1;
    }

    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < size; i++) {

        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
    
        else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        return -1; 
    }

    return second;
}
