//Ques 18:Write a program to Check strong number.
#include<stdio.h>
int main()
{
    int num,i,rem,sum=0,fact=1;
    int original;
    printf("enter the numbers:");
    scanf("%d",&num);
    original=num;
    while (num>0)
    {   
        rem=num%10;
         for(int i=1;i<=rem;i++)
        {
          fact=fact*i;
        }
        sum+=fact;
        fact=1;
        num=num/10;
    } 
    num=original;
    if( num==sum){
        printf("%d is strong number", num);
    }
    else {
        printf("%d is not a strong number",num);
    }
    return 0;
}