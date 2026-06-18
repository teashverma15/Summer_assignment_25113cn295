//Ques 70:Write a program to Selection sort. 
#include<stdio.h>
int main()
{
    int min,temp,n,i,j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];    
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
               min=j;
            }
            if(min!=i){
               temp=arr[i];
               arr[i]=arr[min];
               arr[min]=temp;
            }
        }
    }
    printf("sorted array in ascending order:\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}