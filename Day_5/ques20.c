//Ques 20:Write a program to Find largest prime factor.
#include <stdio.h>

int main() 
{
    int num, i,maxfact = -1;
    printf("Enter a number:");
    scanf("%d", &num);

    while (num%2 == 0) 
    {
       maxfact = 2;
        num /= 2;
    }

    for (i=3;i*i<= num;i=i+2)  
    {
        while (num%i == 0) {
          maxfact = i;
            num /= i;
        }
    }

    if (num>2) {
    maxfact = num;
    }
    printf("Largest prime factor = %d\n",maxfact);
    return 0;
}