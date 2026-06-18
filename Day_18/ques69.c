//Ques 69:Write a program to Bubble sort. 
#include<stdio.h>
int main()
{
    int swap,n,i,j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];    
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    printf("sorted array in ascending order:\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);

    }
    return 0;
}