//Ques 43:Write a program to Write function to check prime. 
#include<stdio.h>

int prime(int num);

int main(){
    int number;
    printf("Enter a positive number:");
    scanf("%d",&number);
    if (prime(number)){
        printf("%d is a prime number", number);
    } 
    else {
        printf("%d is not a prime number", number);
    }

    return 0;
}

int prime(int num){
    if(num<=1){
        return 0;
    }

    for ( int i =2; i<num; i++) 
    {
        if (num % i == 0) 
        {
            return 0;

        }
    }
    return 1;
}