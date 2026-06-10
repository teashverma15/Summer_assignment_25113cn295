//Ques 40:Write a program to Print character pyramid. 
#include<stdio.h>
int main ()
{
    int i,j,k;
   int size=5;
   for(i=0;i<=size-1;i++){
    for(j=0;j<size-i-1;j++){
        printf(" ");
    }
    for(k=0;k<=i;k++){
        printf("%c",'A'+ k);
    }
    for(k=i-1;k>=0;k--){
        printf("%c",'A'+ k);
    }
    printf("\n");
   }
}
