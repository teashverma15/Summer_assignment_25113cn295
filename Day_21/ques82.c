//Ques 82:Write a program to Reverse a string. 
#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="Hello world";
    int left,right;
    char temp;

    printf("original string:%s\n",str);
    left = 0;
    right = strlen(str)-1;

    while(left < right)
    {
        temp=str[left];
        str[left]=str[right];
        str[right]=temp;

        left++;
        right--;

    }
    printf("reversed string:%s\n",str);
    return 0;
}