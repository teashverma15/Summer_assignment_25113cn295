//Ques 17:Write a program to Check perfect number.
#include <stdio.h>
int main() 
{
int num,sum =0,i;
    printf("enter the numbers:");
    scanf("%d",&num);
    
    for(i=1;i<=num-1;i++)
    {
        if(num%i==0)
        {
            sum+=i;
        }
    }
    if(sum==num){
        printf("%d is a perfect number",num);
    }
    else {
        printf("%d is not a perfect number",num);
    }
    return 0;
}