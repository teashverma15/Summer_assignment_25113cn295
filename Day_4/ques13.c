//Ques 13:Write a program to Generate Fibonacci series.
#include<stdio.h>
int main()
{
    int i,n=10;
    int a=0,b=1,c;
    printf("fibonacci series=");
    printf("%d\t%d",a,b);
    for(i=0;i<=n;i++)
    {
       c=a+b;
       a=b;
       b=c;
       printf("\t%d",c);
    }
    return 0;
}