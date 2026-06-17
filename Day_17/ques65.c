//Ques 65:Write a program to Merge arrays.
#include<stdio.h>
int main()
{ 
    int arr1[50],arr2[50];
    int i,size1,size2,merged[100] ;
    printf("Enter the size of both the arrays :");
    scanf("%d%d",&size1,&size2);
    printf("\n Enter the first array elements:\n",size1);
    for(i=0;i<size1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("\n Enter the second array elements:\n",size2);
    for(i=0;i<size2;i++){
        scanf("%d",&arr2[i]);
    }
    for(i=0;i<size1;i++){
        merged[i]=arr1[i];
    }
    for(i=0;i<size2;i++){
        merged[size1+i]=arr2[i];
    }
    printf("the merged array is :\n");
    for(i=0;i<size1+size2;i++){
        printf("%d\n",merged[i]);
    }

    return 0;
}