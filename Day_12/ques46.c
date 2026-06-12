//Ques 46:Write a program to Write function for Armstrong. 
#include<stdio.h>
#include<math.h>

int armstrong(int num);

int main (){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    if(armstrong(n))
   {
    printf("Armstrong number");
   }
    else
   {
    printf("Not a Armstrong number");
   }
   return 0;
}

int armstrong(int num) {
    int rem, count = 0, sum = 0;
    int temp = num;
    int original_num = num;

    while (temp > 0) {
        temp /= 10;
        count++;
    }
    temp = num;
    while (temp > 0) {
        rem = temp % 10;
        sum += round(pow(rem, count));
        temp /= 10;
    }


    if (sum == original_num) {
        return 1;
    } else {
        return 0;
    }
}