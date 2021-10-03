#include <stdio.h>
#include <stdlib.h>

int main()
{int a[10]={6,3,8,10,16,7,5,2,9,14};
int h=a[0],i,*hasht,j;
for(i=0;i<10;i++)
{
    if(a[i]>h)
    {
        h=a[i];
    }
}
hasht=(int*)malloc((h+1)*sizeof(int));
for(i=0;i<h+1;i++)
{
    hasht[i]=0;
}
for(i=0;i<10;i++)
{   j=10-a[i];
    if(j>=0)
    {if(hasht[j]!=0)
    {
        printf("%d + %d = %d \n",a[i],j,10);
    }
    hasht[a[i]]++;
    }
}
}
