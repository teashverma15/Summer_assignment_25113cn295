//Ques 85:Write a program to Check palindrome string. 
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100] , original[100];
    int left,right;
    char palindrome =1;

    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str,"\n")]='\0';
    left = 0;
    right = strlen(str)-1;

    while(left < right)
    {  if(str[left]!=str[right]){
           palindrome=0;
           break;
        }
        left++;
        right--;

    }
    if(palindrome){
        printf("The given string is palindrome");
    }
    else{
        printf("The given string is not palindrome");
    }
    return 0;
}
