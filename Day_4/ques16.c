//Ques 16:Write a program to Print Armstrong numbers in a range.
#include<stdio.h>
#include<math.h>
int main()
{
    int n1,n2,sum,i,rem,count,temp;
    printf("enter the range:");
    scanf("%d%d",&n1,&n2);
        printf("Armstrong number between %d and %d are=",n1,n2);

    for(i=n1;i<=n2;i++)
    {   count=0;
        temp=i;
        sum=0;
    while (temp > 0)
        {
              temp=temp/10;
              count++;
        }
           temp = i;
    while (temp > 0)
        {
            rem = temp % 10;
            sum += round(pow(rem, count));
            temp=temp/ 10;
        }
            if(sum==i){
        printf("%d\t",i);
        }
    }
        return 0;
}