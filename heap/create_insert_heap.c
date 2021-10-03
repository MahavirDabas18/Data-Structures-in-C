#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct heap
{
    int size;
    int capacity;
    int* a;
};
struct heap* heapcreate(int x)
{
    struct heap *p;
    p=(struct heap*)malloc(sizeof(struct heap));
    p->capacity=x;
    p->size=0;
    p->a=(int*)malloc(x*sizeof(int));
    return p;
}
void heapinsert(struct heap* p,int x)
{
    if(p->size==p->capacity)
    {
        printf("overflow \n");
        return;
    }
    p->a[p->size]=x; /*insert  in the next free space*/
    p->size++; /*update the size of heap*/
    int i=p->size-1; /*i is now pointing on the index of the last element in the binary heap*/
    int j; /*to track the parent index of i*/
    if(i%2==0)
    {
        j=(i/2)-1;
    }
    else
    {
        j=(i/2);
    }
    /*j now points on the parent of i*/
    while(i>=0) /*when i becomes zero we stop because then there are no parents to compare to*/
    {
        if(p->a[i]>p->a[j]) /*child becomes greater than parent*/
        {
            swap(&p->a[i],&p->a[j]);
            i=j; /*child now comes to parent index*/
            if(i%2==0)
            {
                j=(i/2)-1;
            }
            else
            {
                j=(i/2);
            }
            /*j now points to the parent of new i*/
        }
        else /*parent is greater than equal to index so we break as we have inserted in a max heap already so no need to check for other nodes*/
        {
            break;
        }
    }
}
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printheap(struct heap* p)
{
    int i;
    for(i=0;i<p->size;i++)
    {
        printf("%d ",p->a[i]);
    }
}
int main()
{
    struct heap* h;
    h=heapcreate(10); /*heap of capacity 10 is created*/
    heapinsert(h,6);
    heapinsert(h,12);
    heapinsert(h,10);
    heapinsert(h,5);
    heapinsert(h,15);
    heapinsert(h,20);
    heapinsert(h,30);
    heapinsert(h,40);
    printf("the generated heap is: \n");
    printheap(h);
}
