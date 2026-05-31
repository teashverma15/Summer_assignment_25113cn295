//Ques 3:Write a program to Find factorial of a number.
#include<stdio.h>
int main()
{
  int fact,n;
  printf("Enter the number:");
  scanf("%d",&n);
   fact=1;
  for(int i=1;i<=n;i++)
  {
     fact=fact*i;
  }
  printf("factorial of %d=%d",n,fact);
  return 0;
}