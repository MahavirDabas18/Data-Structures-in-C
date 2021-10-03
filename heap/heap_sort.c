#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct array
{
    int size;
    int  capacity;
    int* a;
};
struct array* createarray(int x)
{
    struct array* p=(struct array*)malloc(sizeof(struct array));
    p->size=0;
    p->capacity=x;
    p->a=(int*)malloc(x*sizeof(int));
    return p;
}
void insertarray(struct array* p,int x)
{
    if(p->capacity==p->size)
    {
        printf("overflow \n");
        return;
    }
    p->a[p->size]=x;
    p->size++;
}
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(struct array* p,int index)
{
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;
    if(p->a[left]>p->a[largest] && left<p->size /*valid ondex*/)
    {
        largest=left;
    }
    if(p->a[right]>p->a[largest] && right<p->size /*valid index*/)
    {
        largest=right;
    }
    if(largest!=index)
    {
        swap(&p->a[largest],&p->a[index]);
        heapify(p,largest);
    }
}
void makeheap(struct array *p)
{
    int i=(p->size/2)-1; /*i is on the last node before which leaf nodes start*/
    for(;i>=0;i--)
    {
        heapify(p,i); /*we'll heapify all the non leaf nodes in reverse order*/
    }
}
void heapdelete(struct array* p)
{
    if(p->size==0)
    {
        printf("underflow \n");
        return;
    }
    swap(&p->a[0],&p->a[(p->size)-1]);
    p->size--;
    int i=0;
    int j=2*i+1; /*to track the left child*/
    while(j<p->size)
    {
        if(p->a[j+1]>p->a[j] && j+1<p->size /*valid size*/) /*if right child is greater than left child and right child is within limit*/
        {
            j++; /*j now points on right child*/
        }
        if(p->a[j]>p->a[i]) /*parent greater than child*/
        {
            swap(&p->a[i],&p->a[j]);
            i=j; /* i comes to new position as the element comes to the position where it's child was*/
            j=2*i+1; /*j points to the new left child*/
        }
        else /*parent is greater than both children*/
        {
            break;
        }
    }
}
void printarray(struct array* p)
{
    int i;
    for(i=0;i<p->size;i++)
    {
        printf("%d ",p->a[i]);
    }
}
void heapsort(struct array* p)
{
    makeheap(p);
    /*the array is converted into a heap*/
    int i=p->size; /*to save the size of the heap so we know how many elements were there in heap before deletion*/
    /*now we delete all the elements in the heap till size of heap becomes zero*/
    while(p->size!=0)
    {
        heapdelete(p);
    }
    /*now the elements in the array are sorted from heap sort so we just print them*/
    int j;
    for(j=0;j<i;j++) /*the value of number of elements in heap before deletion stored in i is used here*/
    {
        printf("%d ",p->a[j]);
    }
}
int main()
{
    struct array *p=createarray(10);
    insertarray(p,9);
    insertarray(p,6);
    insertarray(p,5);
    insertarray(p,8);
    insertarray(p,2);
    insertarray(p,7);
    insertarray(p,1);
    insertarray(p,3);
    printf("the array before heap sort: \n");
    printarray(p);
    printf("\n");
    printf("elements in the sorted order after performing heap sort: \n");
    heapsort(p);
}
