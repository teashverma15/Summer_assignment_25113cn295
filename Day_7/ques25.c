//Ques 25:Write a program to Recursive factorial. 
#include<stdio.h>

int factorial(int x)
{
    if(x<=1)
    return 1;
    else 
    return x*factorial(x-1);
}

int main ()
{
  int num,fact;
  printf("Enter a number:");
  scanf("%d",&num);
  fact = factorial(num);
  printf("factorial of %d is %d ",num,fact);
  return 0;
}