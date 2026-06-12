//Ques 51:Write a program to Find largest and smallest element. 
#include<stdio.h>
int main()
{
    int i,max,min,n ;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    min=a[0],max=a[0];
    for(i=0;i<n;i++){
        if(a[i]<min){
            min=a[i];
        }
        if(a[i]>max){
            max=a[i];
        }
    }
    printf("Maximum value=%d\n",max);
    printf("Minimum value=%d",min);
    return 0;
}