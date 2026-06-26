//Ques 104:Write a program to Create quiz application.
#include <stdio.h>

int main() {
    int score = 0;
    int answer;

    printf(" Welcome to the Quiz Application \n");

    // Question 1
    printf("Q1. What is the size of 'int' in C (usually)?\n");
    printf("1) 2 bytes  2) 4 bytes  3) 8 bytes\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if(answer == 2) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer.\n");
    }

    // Question 2
    printf("Q2. Which keyword is used to prevent any changes to a variable?\n");
    printf("1) static   2) mutable  3) const\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if(answer == 3) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer.\n");
    }

    printf(" Quiz Finished! \n");
    printf("Your total score: %d/2\n", score);

    return 0;
}