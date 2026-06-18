//Ques 71:Write a program to Binary search. 
#include<stdio.h>
int main()
{
    int swap,n,i,j,search,beg,end,mid;
    int flag=0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];    
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value to be searched:");
    scanf("%d",&search);
    beg=0;
    end=n-1;
   
    while(beg<=end){
        mid=beg+(end-beg)/2;
        
        if(arr[mid]<search){
            beg=mid+1;
        }
        else if (arr[mid]==search){
            printf("%d found at index: %d and positon: %d",search,mid,mid+1);
            flag=1;
            break;
        }
        else{
            end=mid-1;
        }
    }

    if(flag==0){
        printf("Not found");
    }
    return 0;
}