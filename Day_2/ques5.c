//Ques 5:Write a program to Find sum of digits of a number. 
#include<stdio.h>
int main()
{
    int n,remainder,sum=0;
    printf("Enter the number:");
    scanf("%d",&n);
    while(n>0)
   {
    remainder=n%10;
    sum+=remainder;
    n=n/10;
   }
   printf("sum of digit of the number=%d",sum);
   return 0;
}