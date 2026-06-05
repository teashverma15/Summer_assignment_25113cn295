//Ques 21:Write a program to Convert decimal to binary. 
#include<stdio.h>
int main()
{
    int num,temp,ans=0;
    printf("Enter a number:");
    scanf("%d",&num);
    int pow=1; 
    while(num>0)
    {   
        temp=num%2;
        num =num/2;
        ans+=(temp*pow);
        pow=pow*10;
    }
    printf("%d",ans);
    return 0;
}
