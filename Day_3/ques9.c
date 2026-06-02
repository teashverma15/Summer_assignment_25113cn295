//Ques 9:Write a program to Check whether a number is prime.
#include <stdio.h>

int main()
{
    int n, i, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) 
    {
        if (n % i == 0) 
        {
            flag ++;
        }
    }

    if (flag == 2)
        printf("%d is a prime number.", n);
    else
        printf("%d is not a prime number.", n);

    return 0;
}