#include <stdio.h>
#include <stdlib.h>

int main()
{int a=20;
void fun1(int);
void fun2(int);
fun1(20);
}
void fun2(int n); /*for removing implicit declaration-yo can check its affect by removing this and then try to run program*/
void fun1(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        fun2(n-1);
    }
}
void fun2(int n)
{
    if(n>1)
    {
        printf("%d ",n);
        fun1(n/2);
    }
}

