#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct array
{
    int size;
    int capacity;
    int* p;
};
struct array* createarray(int x)
{
    struct array* p=(struct array*)malloc(sizeof(struct array));
    p->size=0;
    p->capacity=x;
    p->p=(int*)malloc(x*sizeof(int));
    return p;
}
void insertarray(struct array* a,int x)
{
    if(a->size==a->capacity)
    {
        printf("overflow \n");
        return;
    }
    a->p[a->size]=x;
    a->size++;
}
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(struct array* a,int index) /*send the array and the index to be heapified*/
{
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;
    if(a->p[left]>a->p[largest] && left<a->size /*for valid index*/)
    {
        largest=left;
    }
    if(a->p[right]>a->p[largest] && right<a->size /*for valid index*/)
    {
        largest=right;
    }
    if(largest!=index) /*the root needs  to be heapified as one of the children is larger than parent*/
    {
        swap(&a->p[index],&a->p[largest]);
        heapify(a,largest); /*the swapped node may get affected so we call heapify on it recursively to heapify it*/
    }
    else /*parent is the largest or it is a leaf node as both left and right are out of range*/
    {
        return;
    }
}
void makeheap(struct array* a)
{
    int x=a->size;
    int i=(x/2)-1; /*i is at the node which is just before the leaf nodes start-from n/2 to n*/
    for(;i>=0;i--)
    {
        heapify(a,i); /*we heapify all the non leaf nodes as the leaf nodes are already a heap*/
    }

}
void printarray(struct array* a)
{
    int i;
    for(i=0;i<a->size;i++)
    {
        printf("%d ",a->p[i]);
    }
}
int main()
{
    struct array* a=createarray(10);
    insertarray(a,9);
    insertarray(a,6);
    insertarray(a,5);
    insertarray(a,8);
    insertarray(a,2);
    insertarray(a,7);
    insertarray(a,1);
    insertarray(a,3);
    printf("the array before heapify: \n");
    printarray(a);
    printf("\n");
    makeheap(a);
    printf("the array after heapify: \n");
    printarray(a);
}
