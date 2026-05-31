//Ques 2:Write a program to Print multiplication table of a given number. 
#include<stdio.h>
int main()
{
    int n,i,table;
    printf("Enter the number :");
    scanf("%d",&n);
    for(i=1;i<=10;i++)
    {
        table=n*i;
        printf(" %d*%d = %d",n,i,table);
        printf("\n");
    }
    return 0;
}