#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void merge(int a[],int l,int mid,int h)
{
    int i=l; /*traverses first list*/
    int j=mid+1; /*traverses second list*/
    int k=l; /*traverses auxiliary array*/
    int* b=(int*)malloc((h+1)*sizeof(int));
    while(!(i>mid || j>h))
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    for(;i<=mid;i++)
    {
        b[k]=a[i];
        k++;
        /*i wont be incremented because it is incremented by the for loop*/
    }
    for(;j<=h;j++)
    {
        b[k]=a[j];
        k++;
        /*j wont be incremented because it is incremented by the for loop*/
    }
    /*now elements are stored in a sorted manner in auxiliary array between elements l and h, we just copy them back to original array*/
    for(i=l;i<=h;i++)
    {
        a[i]=b[i];
    }
}
void MergeSort(int a[],int l,int h)
{
    if(l==h || l>h) /*base case- case of one element(already sorted) and case of invalid index*/
    {
        return; /*do nothing in this case*/
    }
    /*other case*/
    int mid=(l+h)/2;
    MergeSort(a,l,mid); /*left half of the list is sorted*/
    MergeSort(a,mid+1,h); /*right half of the list is sorted*/
    merge(a,l,mid,h); /*merge the two sorted halves*/
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int l=0;
    int h=9;
    MergeSort(a,l,h);
    int i;
    printf("the sorted list is: \n");
    for(i=l;i<=h;i++)
    {
        printf("%d ",a[i]);
    }
}
