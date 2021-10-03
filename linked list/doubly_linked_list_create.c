#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* head;
int main()
{
    struct node* create(int a[],int);
    void display(struct node*);
    int count(struct node*);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    printf("the doubly linked list is: \n");
    display(head);
    printf("the number of elements in the linked list are: %d \n",count(head));
}
struct node* create(int a[],int n)
{
    struct node *p,*t,*last;
    p=(struct node*)malloc(sizeof(struct node));
    p->prev=NULL;
    p->data=a[0];
    p->next=NULL;
    last=p;
    int i;
    for(i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
    return p;
}
void display(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
int count(struct node* p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}
