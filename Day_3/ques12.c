//Ques 12:Write a program to Find LCM of two numbers. 
#include<stdio.h>
int main()
{
    int num1,num2,lcm,n,small,count;
    printf("enter two numbers:");
    scanf("%d%d",&num1,&num2);
     small=(num1<num2)?num1:num2;
    for(count=1;count<=small;count++)
    {
        if(num1%count==0 && num2%count==0)
        {
            n=count;
        }
    }
    lcm=(num1*num2)/n;
    printf("LCM of two numbers=%d",lcm); 
    return 0;
}