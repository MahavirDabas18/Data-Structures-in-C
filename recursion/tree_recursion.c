#include <stdio.h>
#include <stdlib.h>

int main()
{int a=3;
int fun(int);
printf("%d \n",fun(a));
}
int fun(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        fun(n-1);
        fun(n-1);
    }
}

