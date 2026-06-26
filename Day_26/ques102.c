//Ques 102:Write a program to Create voting eligibility system. 
#include<stdio.H>
int main()
{
   
    int age;
    printf("Enter your age:");
    scanf("%d",&age);

    if(age>=18){
        printf("Eligible for voting.");
    }
    else{
        printf("Not Eligible.");
    }
    return 0;
}