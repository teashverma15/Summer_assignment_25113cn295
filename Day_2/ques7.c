//Ques 7:Write a program to Find product of digits.
#include<stdio.h>
int main()
{
     int n,remainder,product=1;
    printf("Enter the number:");
    scanf("%d",&n);
    while(n>0)
   {
    remainder=n%10;
   product=product*remainder;
    n=n/10;
}
printf("product of digit=%d",product);
return 0;
}