//Ques 10:Write a program to Print prime numbers in a range. 

#include<stdio.h>
int main()
{
    int n1,n2,j,i,count=0;
    printf("enter the range:");
    scanf("%d%d",&n1,&n2);
    for(i=n1;i<=n2;i++)
    { 
        count=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {count++;}

        }
        if(count==2)
        {
            printf("%d\n",i);
        }
    }return 0;
}
