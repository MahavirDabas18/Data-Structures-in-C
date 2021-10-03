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
   if(l<=h)
   {
       mid=(l+h)/2;
       if(key==p.a[mid])
       {
           return mid;
       }
       else if(key<=p.a[mid])
       {
           return binsearch(p,l,mid-1,key);
       }
       else
       {
           return binsearch(p,mid+1,h,key);
       }
   }
}






