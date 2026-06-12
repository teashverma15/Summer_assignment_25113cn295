//Ques 52:Write a program to Count even and odd elements.
#include<stdio.h>
int main()
{
    int i,even=0,odd=0,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            even+=1;
        }
        else{
           odd+=1;
        }
    }
    printf("Even number=%d\n",even);
    printf("Odd number=%d",odd);
    return 0;
}