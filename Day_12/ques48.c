//Ques 48:Write a program to Write function for perfect number.
#include<stdio.h>

int perfect(int n);

int main(){
    int num;
    printf("enter the numbers:");
    scanf("%d",&num);
    if(perfect(num)){
        printf("%d is a perfect number",num);
    }
    else {
        printf("%d is not a perfect number",num);
    }
    return 0;
}

int perfect(int n){
    int sum =0,i;
  for(i=1;i<=n-1;i++)
    {
        if(n%i==0)
        {
            sum+=i;
        }
    }  
     if(sum==n){
        return 1;
    }
    else {
       return 0;
    }
}