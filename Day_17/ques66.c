//Ques 66:Write a program to Union of arrays.
#include <stdio.h>

int main() 
{
    
    int i, j, k = 0, isDuplicate;
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int unionArr[n1 + n2];
    for (i = 0; i < n1; i++) {
        isDuplicate = 0;
        for (j = 0; j < k; j++) {
            if (arr1[i] == unionArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionArr[k] = arr1[i];
            k++;
        }
    }
    for (i = 0; i < n2; i++) {
        isDuplicate = 0;
        for (j = 0; j < k; j++) {
            if (arr2[i] == unionArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionArr[k] = arr2[i];
            k++;
        }
    }
    printf("\nUnion of the two arrays is:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}