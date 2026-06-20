//Ques 77:Write a program to Check symmetric matrix.
#include <stdio.h>

int main() {
    int rows, cols, i, j, symmetric = 1;
    int matrix[10][10];

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    if (rows != cols) {
        printf("The matrix is not symmetric (not square).\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    if (symmetric)
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}