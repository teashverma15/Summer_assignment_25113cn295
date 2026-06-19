//Ques 75:Write a program to Transpose matrix.
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
    for(i = 0;i < rows; i++ ){
        for( j = 0; j < cols; j++){
            mat2[j][i]=mat1[i][j];
        }
    }
    printf("Print the transpose matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
           printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    return 0;
}