#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void CountSort(int a[],int n)
{
    int i,max;
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    int *b=(int*)malloc((max+1)*sizeof(int));
    for(i=0;i<=max;i++)
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    int j=0;
    i=0;
    while(i<=max)
    {
        if(b[i]==0)
        {
            i++;
        }
        else
        {
            a[j]=i;
            b[i]--;
            j++;
        }
    }
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    CountSort(a,n);
    int i;
    printf("the sorted list will be: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
