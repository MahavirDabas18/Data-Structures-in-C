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
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
struct heap* heapcreate(int x)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=x;
    h->a=(int*)malloc(x*sizeof(int));
    return h;
}
void heapinsert(struct heap* h,int x)
{
    if(h->size==h->capacity)
    {
        printf("overflow \n");
        return;
    }
    h->a[h->size]=x;
    h->size++;
    int i=h->size-1; /*to track the inserted element*/
    int j; /*to track the parent of i*/
    while(i>=0) /*do this till i reaches 0 because then there can't be any more parents*/
    {
        if(i%2==0)
        {
            j=(i/2)-1;
        }
        else
        {
            j=i/2;
        }
        /*j now points on the parent of i*/
        if(h->a[i]>h->a[j]) /*child is larger than parent*/
        {
            swap(&h->a[j],&h->a[i]);
            i=j;
        }
        else /*parent becomes larger than child*/
        {
            break;
        }
    }
}
void heapdelete(struct heap* h)
{
    if(h->size==0)
    {
        printf("underflow \n");
        return;
    }
    swap(&h->a[0],&h->a[(h->size)-1]);
    h->size--;
    int i=0;
    int j=(2*i)+1; /*tracks the left child of i*/
    while(j<h->size)
    {
        if(h->a[j+1]>h->a[j] && j+1<h->size)
        {
            j++;
        }
        if(h->a[j]>h->a[i]) /*child becomes greater than parent*/
        {
            swap(&h->a[i],&h->a[j]);
            i=j; /*i comes to new position of element*/
            j=(2*i)+1; /*j comes to left child of new position of i*/
        }
        else /*parent is larger than child*/
        {
            break;
        }
    }
}
void heapprint(struct heap *h)
{
    int i;
    for(i=0;i<h->size;i++)
    {
        printf("%d ",h->a[i]);
    }
}
int main()
{
    struct heap* h;
    h=heapcreate(10);
    heapinsert(h,6);
    heapinsert(h,12);
    heapinsert(h,10);
    heapinsert(h,5);
    heapinsert(h,15);
    heapinsert(h,20);
    heapinsert(h,30);
    printf("the heap before deletion is: \n");
    heapprint(h);
    printf("\n");
    heapdelete(h);
    heapdelete(h);
    heapdelete(h);
    printf("the heap after deletion is: \n");
    heapprint(h);
}
