#include<stdio.h>
int main()
{
    int i,n,count=1;
    printf("Enter the integers");
    for(i=0;i<10;i++)
    {
        scanf("%d",&n);

    if(n%2!=0)
    {
        count*=n;



    }
    }
    printf("The Multiplication of odd numbers is%d\n",count);
    return 0;

}