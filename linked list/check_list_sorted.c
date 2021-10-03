#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;
int main()
{
    int x;
    struct node* create(int a[],int);
    int sorted(struct node*);
    int a[]={1,2,3,10,5};
    head=create(a,5);
    x=sorted(head);
    x==0?printf("the list is not sorted \n"):printf("the list is sorted \n");
}
struct node* create(int a[],int n)
{struct node *p,*t,*last;
p=(struct node*)malloc(sizeof(struct node));
p->data=a[0];
p->next=NULL;
last=p;
int i;
for(i=1;i<n;i++)
{
    t=(struct node*)malloc(sizeof(struct node));
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
}
    return p;
}
int sorted(struct node* p)
{
    int x=-32768; /*smallest possible int value*/
    while(p!=NULL)
    {
        if(p->data<x)
        {
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}
