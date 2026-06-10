//Ques 39:Write a program to Print number pyramid. 
#include<stdio.h>
int main()
{
   int i,j,k;
   int size=5;
   for(i=1;i<=size;i++){
    for(j=1;j<=size-i;j++){
        printf(" ");
    }
    for(k=1;k<=i;k++){
        printf("%d",k);
    }
    for(k=i-1;k>=1;k--){
        printf("%d",k);
    }
    printf("\n");
   }
   return 0;
}