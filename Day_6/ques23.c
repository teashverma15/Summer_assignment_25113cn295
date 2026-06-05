//Ques 23:Write a program to Count set bits in a number. 
#include<stdio.h>
int main()
{
    int n,count=0;
    printf("Enter a number :");
    scanf("%d",&n);

    while (n>0){
        n&=(n-1);
        count++;
    }
    printf("%d",count);
    return 0;
}