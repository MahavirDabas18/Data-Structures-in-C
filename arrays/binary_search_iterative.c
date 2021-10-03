#include <stdio.h>
#include <stdlib.h>
struct array
{
    int a[10];
    int size;
    int length;
};
struct array p={{1,2,3,4,5,6},10,6};
int binsearch(struct array,int,int,int);


int main()
{printf("%d ",binsearch(p,0,(p.length-1),6));
}
int binsearch(struct array p,int l,int h,int key)
{int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==p.a[mid])
        {
            return mid;
        }
        else if(key<p.a[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}






