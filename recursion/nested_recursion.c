#include <stdio.h>
#include <stdlib.h>

int main()
{int a=95;
int fun(int);
printf("%d \n",fun(a));
}
int fun(int n)
{
    if(n>100)
    {
        return n-10;
    }
    else
    {
        return fun(fun(n+11));
    }
}
