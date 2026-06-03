//Ques 15:Write a program to Check Armstrong number. 
#include<stdio.h>
#include<math.h>
int main()
{
    int n,rem,num=0,count=0;
    printf("Enter the number:");
    scanf("%d",&n);
    int original_num;
    original_num=n;
    while(n>0)
   {
    rem=n%10;
    count=count+1;
    n=n/10;
   }
   n=original_num;
   while (n>0)
   { 
    rem=n%10;
    num+=round(pow(rem,count));
    n=n/10;
   } 
   if(num==original_num)
   {
    printf("Armstrong number");
   }
    else
   {
    printf("Not a Armstrong number");
   }
   return 0;
}