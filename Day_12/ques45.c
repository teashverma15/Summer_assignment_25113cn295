//Ques 45:Write a program to Write function for palindrome. 
#include<stdio.h>

int palindrome(int num );

int main (){
  int n;
  printf("Enter the number:");
  scanf("%d",&n);
  if (palindrome(n)){
  printf("%d is a palindrome number.",n );
  }
  else{
    printf("%d is not a palindrome number.",n);
  }
  return 0;
}

int palindrome(int num ){
    int original = num;
    int rev = 0;
    int r;

    while (num > 0) {
        r = num % 10;
        rev = (rev * 10) + r;
        num = num / 10;
    }

    if (original == rev) {
        return 1; 
    }
    else {
        return 0;
    }

}