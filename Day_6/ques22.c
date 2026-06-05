//Ques 22:Write a program to Convert binary to decimal.
#include<stdio.h>
#include<math.h>
int main ()
{
    int num,ans=0,temp,p=0;
    printf("Enter a number:");
    scanf("%d",&num);
    while(num>0)
    {
        temp=num%10;
        ans+=round(pow(2,p))*temp;
        num=num/10;
        p++;
    } 
    printf("%d",ans);
    return 0;
}