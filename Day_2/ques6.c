//Ques 6:Write a program to Reverse a number
#include<stdio.h>
int main()
{
int n,r=0,rev=0;
printf("Enter a number:");
scanf("%d",&n);
while(n>0)
{
    r=n%10;
    rev=rev*10+r;
    n=n/10;
}
printf("reverse=%d",rev);
return 0;
}