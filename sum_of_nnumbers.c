#include<stdio.h>
int main()
{
    int n,ary[10],i=1,sum=0;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    while(i<=n)
    {
        printf("Enter %d element :",i);
        scanf("%d",&ary[i]);
        sum=sum+ary[i];
        i=i+1;
    }
    printf("sum is %d",sum);
    return 0;
}