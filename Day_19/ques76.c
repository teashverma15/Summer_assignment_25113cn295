//Ques 76:Write a program to Find diagonal sum. 
#include <stdio.h>

int main() {
    int size;
    int matrix[10][10];
    int principal_sum = 0;
    int secondary_sum = 0;

    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &size);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        principal_sum += matrix[i][i];              
        secondary_sum += matrix[i][size - i - 1];     
    }

    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of Principal Diagonal elements: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal elements: %d\n", secondary_sum);

    return 0;
}