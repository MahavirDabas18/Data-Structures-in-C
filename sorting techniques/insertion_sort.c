#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void InsertionSort(int a[],int n)
{
    int i; /*to track passes*/
    int j; /*to track comparisons*/
    for(i=1;i<=n-1;i++)
    {
        int x=a[i]; /*stores the element to be inserted*/
        for(j=i-1;j>=0 && a[j]>x;j--)
        {
            if(a[j]>x)
            {
                a[j+1]=a[j];
            }
            else
            {
                break; /*element smaller than the one to be inserted*/
            }
        }
        /*if we reach here either j is at -1 or the element at j is smaller than the one to be inserted*/
        a[j+1]=x;
    }
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    InsertionSort(a,n);
    printf("the sorted list will be: \n");
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
