//Ques 14:Write a program to Find nth Fibonacci term. 
#include<stdio.h>
int main()
{
    int i,n;
    int a=0,b=1,c;
    printf("enter a number:");
    scanf("%d",&n);
    printf("fibonacci series=");
    printf("%d\t%d",a,b);
    for(i=0;i<=n;i++)
    {
       c=a+b;
       a=b;
       b=c;
       printf("\t%d",c);
    }
    printf("\nnth fibonacci term=%d",c);
    return 0;
}