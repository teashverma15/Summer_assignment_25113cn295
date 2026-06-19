//Ques 73:Write a program to Add matrices. 
#include<stdio.h>
int main()
{
    int mat1[25][25],i,j,n,sum[25][25],mat2[25][25];
    int rows,cols;
    printf("Enter the rows and columns:");
    scanf("%d%d",&rows,&cols);

    printf("Enter the elements of first matrix:");
     for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nEnter elements for the second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("\nResultant Matrix (Sum):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
