//Ques 19:Write a program to Print factors of a number. 
#include <stdio.h>
int main() 
{
   int num,i;
    printf("enter the numbers:");
    scanf("%d",&num);
    printf("factors=");
    for(i=1;i<=num;i++)
    {
        if(num%i==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}