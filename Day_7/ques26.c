//Ques 26:Write a program to Recursive Fibonacci. 
#include<stdio.h>

void fibonacci( int num, int a, int b)
{
   if (num>0){
    printf("%d ",a);
    fibonacci(num-1,b,a+b); 
   }
}

int main()
{
    int num_term = 8;
    printf("Fibonacci series:");
    fibonacci(num_term,0,1);
    return 0;
}