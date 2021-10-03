#include <stdio.h>
#include <stdlib.h>

int main()
{int fun(int,int);
int pow(int,int);
printf("%d \n",fun(2,9));
}
int fun(int m,int n)
{
    if(n%2==0)
    {
        return power(m*m,n/2);
    }
    else
    {
        return m*power(m*m,n/2);
    }
}
int power(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return m*power(m,n-1);
    }
}
