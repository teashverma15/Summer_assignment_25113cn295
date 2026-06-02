//Ques 11:Write a program to Find GCD of two numbers. 
#include<stdio.h>
int main ()
{
    int num1,num2,gcd,small,count;
    printf("enter two numbers:");
    scanf("%d%d",&num1,&num2);
    if (num1<num2)
    small =num1;
    else
    small=num2;
    for(count=1;count<=small;count++)
    {
        if(num1%count==0 && num2%count==0)
        {
            gcd=count;
        }
    }
    printf("GCD of two number =%d",gcd);
    return 0;
}