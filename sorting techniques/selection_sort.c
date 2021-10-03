#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int a[],int n)
{
    int i; /*to track passes*/
    int j; /*for traversals*/
    int k; /*to point at minimum*/
    for(i=0;i<n-1;i++) /*passes*/
    {
        k=i; /*minimum*/
        for(j=i+1;j<n;j++) /*traversals*/
        {
            if(a[j]<a[k]) /*if element at j is less than the minimum*/
            {
                k=j; /*minimum points at the new position*/
            }
        }
        /*after full traversal- k points at the minimum element and i points at the position selected for sorting*/
        swap(&a[i],&a[k]);
    }
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    SelectionSort(a,n);
    int i;
    printf("the sorted list is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
