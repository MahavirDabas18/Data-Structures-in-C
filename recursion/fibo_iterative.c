#include <stdio.h>
#include <stdlib.h>
int main()
{int fibo(int);
int n;
printf("enter the term you want to see: \n");
scanf("%d",&n);
printf("%d \n",fibo(n));
}
int fibo(int n)
{
    int t0=0,t1=1,t,i;
    if(n==0||n==1)
    {
        return n;
    }

    else
    { for(i=2;i<=n;i++)
    {
        t=t0+t1;
        t0=t1;
        t1=t;
    }
        return t;
    }
}
