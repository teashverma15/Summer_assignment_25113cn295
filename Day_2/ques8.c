//Ques 8:Write a program to Check whether a number is palindrome. 
#include<stdio.h>
int main()
{
int n,r=0,rev=0;
printf("Enter a number:");
scanf("%d",&n);
int num=n;
while(n>0)
{
    r=n%10;
    rev=rev*10+r;
    n=n/10;
}
if (num==rev)
{
printf("The number is palindrome number ");
}
else
{
    printf("Not a palindrome number ");
}
return 0;
}