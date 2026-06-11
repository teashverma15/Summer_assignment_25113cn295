//Ques 44:Write a program to Write function to find factorial.
#include<stdio.h>

int fact(int num);

int main(){
    int n;
  printf("Enter the number:");
  scanf("%d",&n);
  int result=fact(n); 
  printf("factorial of %d = %d",n,result);
  return 0;
}

int fact(int num){
    int factorial=1;
     for(int i=1;i<=num;i++)
  {
    factorial=factorial*i;
  }
   return factorial;
}