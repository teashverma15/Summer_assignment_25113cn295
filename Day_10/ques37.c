//Ques 37:Write a program to Print star pyramid.
#include<stdio.h>
int main()
{
   int i,j,k;
   int size=5;
   for(i=1;i<=size;i++){
    for(j=1;j<=size-i;j++){
        printf(" ");
    }
    for(k=1;k<=(2*i-1);k++){
        printf("*");
    }
    printf("\n");
   }
   return 0;
}