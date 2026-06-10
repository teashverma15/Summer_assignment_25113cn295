//Ques 38:Write a program to Print reverse pyramid. 
#include<stdio.h>
int main() 
{
int i,j,k;
   int size=5;
   for(i=size;i>=1;i--){
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