#include <stdio.h>
#include <stdlib.h>

int main()
{int a[10]={3,6,8,8,10,12,15,15,15,20};
int i,h=a[0];
int* hasht;
for(i=0;i<10;i++)
{
    if(a[i]>h)
    {
        a[i]=h;
    }
}
hasht=(int*)malloc((h+1)*sizeof(int));
for(i=0;i<h+1;i++)
{
    hasht[i]=0;
}
for(i=0;i<10;i++)
{
    hasht[a[i]]++;
}
for(i=0;i<h+1;i++)
{
    if(hasht[i]>1)
    {
        printf("duplicate element: %d   no of reps: %d \n",i,hasht[i]);
    }
}

}
