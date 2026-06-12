//Ques 50:Write a program to Find sum and average of array. 
#include<stdio.h>
int main(){
    int i,n,a[5],sum=0;
    float avg;
    printf("Enter number of elements less than 5 : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Sum of array is: ");
    for(i=0;i<n;i++){
        sum=sum+a[i];
    }
    avg=(float)sum/n;
    printf("%d\n ",sum);
    printf("Average of array is: %f ",avg);
    return 0;
}