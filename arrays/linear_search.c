#include <stdio.h>
#include <stdlib.h>
struct array
{
    int a[10];
    int size;
    int length;
};
struct array p={{1,2,3,4,5,6},10,6};
int linsearch(struct array,int);
void swap(int*,int*);

int main()
{printf("%d ",linsearch(p,6));
}
void swap(int* x,int* y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
int linsearch(struct array p,int key)
{
    int i;
    for(i=0;i<p.length;i++)
    {
        if(key==p.a[i])
        {
            return i;
        }
    }
    return -1;

}







