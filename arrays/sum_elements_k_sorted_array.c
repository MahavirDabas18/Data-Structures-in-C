#include <stdio.h>
#include <stdlib.h>

int main()
{int a[10]={1,3,4,5,6,8,9,10,12,14};
int i=0,j=9;
while(i<j)
{
    if(a[i]+a[j]==10)
    {
        printf("%d + %d = %d \n",a[i],a[j],10);
        i++;
        j--;
    }
    else if(a[i]+a[j]>10)
    {
        j--;
    }
    else
    {
        i++;
    }
}
}
