#include <stdio.h>
#include <stdlib.h>
int main()
{int c(int,int);
int n,r;
printf("enter the value of n: \n");
scanf("%d",&n);
printf("enter the value of r: \n");
scanf("%d",&r);
printf("the value of nCr will be: %d \n",c(n,r));

}
int c(int n,int r)
{
    if(r==0||n==r)
    {
        return 1;
    }
    else
    {
        return c(n-1,r-1)+c(n-1,r);
    }
}
