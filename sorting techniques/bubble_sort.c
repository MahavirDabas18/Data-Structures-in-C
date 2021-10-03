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
void BubbleSort(int a[],int n)
{
    int i; /*to track passes*/
    int j; /*to track comparisons*/
    int flag; /*to track number of swaps made in each pass*/
    for(i=1;i<=(n-1);i++)
    {
        flag=0; /*before each pass we make flag zero*/
        for(j=0;j<=(n-i-1);j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                flag++;
            }
        }
        /*after each pass we check the number  of swaps made in each pass-if zero swaps then the list is now sorted no need to perform rest of the swaps*/
        if(flag==0)
        {
            break;
        }
    }
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    BubbleSort(a,n);
    int i;
    printf("the sorted list will be: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
