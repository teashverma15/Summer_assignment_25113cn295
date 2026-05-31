//Ques 1:Write a program to Calculate sum of first N natural numbers. 
#include<stdio.h>
int main()
{
    int sum=0,n,i;
    printf("Enter the number till which you want the sum :");
    scanf("%d",&n);
    for (i=0;i<=n;i++)
    {
       sum=sum+i;
    }
    printf("sum upto the given number=%d",sum);
    return 0;
}