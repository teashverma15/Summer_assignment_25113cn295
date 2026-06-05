//Ques 24:Write a program to Find x^n without pow(). 
#include<stdio.h>
int main()
{
    int num,i,temp=1,power;
    printf("Enter the number and the power :");
    scanf("%d%d",&num,&power);
    int original_num;
    original_num=num;
    for(i=1;i<=power;i++){
        temp=temp*num;
        num= original_num;
    }
    printf("%d^%d without pow()=%d",num,power,temp);
    return 0;
}