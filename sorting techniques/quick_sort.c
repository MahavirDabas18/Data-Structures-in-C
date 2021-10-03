#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int a[],int l,int h)
{
    int pivot=l;
    int i=l+1;
    int j=h;
    while(i<j)
    {
        while(!(a[i]>a[pivot] || i==h))
        {
            i++;
        }
        while(!(a[j]<a[pivot] || j==l))
        {
            j--;
        }
        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
    }
    /*now j is less than i and j becomes the partitioning position, so we swap elements at pivot and j*/
    swap(&a[pivot],&a[j]);
    return j; /*the partitioning position is returned*/
}
void QuickSort(int a[],int l,int h)
{
    if(l==h || l>h) /*base case-case of one element(already sorted) and invalid index*/
    {
        return; /*do nothing*/
    }
    int p; /*stores the partitioning position*/
    p=partition(a,l,h);
    QuickSort(a,l,p-1); /*left side of partitioning position is sorted*/
    QuickSort(a,p+1,h); /*right side of partitioning position is sorted*/
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int l=0;
    int h=9;
    QuickSort(a,l,h);
    int i;
    printf("the sorted list will be: \n");
    for(i=l;i<h;i++)
    {
        printf("%d ",a[i]);
    }
}
