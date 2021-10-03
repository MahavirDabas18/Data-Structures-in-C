#include <stdio.h>
#include <stdlib.h>
int p=1;
int f=1;
int main()
{
float e(int x,int n);
int x;
int n;
printf("enter the power of exponential: \n");
scanf("%d",&x);
printf("enter number of terms to be used in series: \n");
scanf("%d",&n);
printf("value of exponential = %f \n",e(x,n));
}
float e(int x,int n)
{
    float r;
    if(n==0)
    {
        return 1;
    }
    else
    {
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+(p/f);
    }
}
