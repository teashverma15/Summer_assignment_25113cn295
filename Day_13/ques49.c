//Ques 49:Write a program to Input and display array.
#include<stdio.h>
int main()
{
    int i,n,a[20];
    printf("Enter number of elements less than 20: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n Content of array is : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}