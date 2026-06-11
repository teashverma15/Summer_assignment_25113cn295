//Ques 42:Write a program to Write function to find maximum.
#include<stdio.h>

int max(int firstnum, int secondnum);

int main(){
   int num1, num2, max_value;
   printf("Enter the numbers:");
   scanf("%d%d",&num1,&num2);
   max_value=max(num1,num2);
   printf(" The maximum number is = %d",max_value);

   return 0;
}

int max(int firstnum, int secondnum){
   return ( firstnum > secondnum)? firstnum : secondnum;
}