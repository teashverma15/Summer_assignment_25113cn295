//Ques 101:Write a program to Create number guessing game. 
#include<stdio.h>
int main()
{
    int number = 25;
    int guess_number ;

    while(1){

        printf("Guess a number(1-50): ");
        scanf("%d",&guess_number);

        if(number > guess_number){
            printf("Try again! Your guess is smaller than the number . "); 
        }
        else if (number < guess_number ){
            printf(" Try again! Your guess is larger than the number .");
        }
        else{
            printf("Congratulations! Right guess .");
            break;
        }
        
        printf("\n");
    }
    
    return 0;
}