//Ques 53:Write a program to Linear search.
#include<stdio.h>
int main (){
    int num,i,n,found=0,pos=-1;
    printf("Enter the number of array: ");
    scanf("%d",&n);
    printf("\n Enter %d elements:\n", n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number that has to be searched: ");
    scanf("%d",&num);
    for(i=0;i<n;i++){
        if(arr[i]==num){
            found=1;
            pos=i;
            printf("\n %d is found in the array at position=%d",num,i);
            break;
        }
    }
    if(found==0){
        printf("\n %d doesnot exist in the array",num);
        return 0;
    }
}