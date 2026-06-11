//Ques 41:Write a program to Write function to find sum of two numbers. 
#include<stdio.h>

int add( int num1, int num2);

int main(){
    int n1,n2;
    printf("Enter the numbers:");
    scanf("%d%d",&n1,&n2);
    int result = add(n1, n2);
    printf("Result=%d",result);
    return 0;

}

int add( int num1, int num2){
    return num1+num2;
}