#include <stdio.h>
#include <stdlib.h>

int main()
{int a[10]={5,8,3,9,6,2,10,7,-1,4};
int i,min,max;
min=max=a[0];
for(i=1;i<10;i++)
{
    if(a[i]>max)
    {
        max=a[i];
    }
    else
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
}
printf("max= %d \n",max);
printf("min= %d \n",min);
}
