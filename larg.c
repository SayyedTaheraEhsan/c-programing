#include<stdio.h>
int main()
{
    int i;
    printf("enter the integer\n");
    scanf("%d",&i);
    if(i<200)
    {
        if(i>100)
        printf("the no is small%d\n",i);
    }
    else if(i>200)
    {
        if(i<1000)
        printf("the no is larg%d\n",i);
    }
    else if(i>1000)
    {
        printf("the no is very large%d\n",i);
    } 
else
 {
     printf("this no is very small%d\n ",i);
 }   
    return 0;

}