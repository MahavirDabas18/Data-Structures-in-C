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
    if(n==0||n==1)
    {
        return n;
    }

    else
    {
        return fibo(n-1)+fibo(n-2);
    }
}
