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
    void insert(struct node*,int,int);
    int count(struct node*);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    printf("the doubly linked list is: \n");
    display(head);
    insert(head,0,0);
    insert(head,6,60);
    printf("the linked list after insertions is: \n");
    display(head);
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
void insert(struct node* p,int index,int x)
{
    struct node* t;
    if(index<0 || index>count(p)) /*case of invalid index*/
    {
        return;
    }
    /*else case*/
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(index==0) /*special case*/
    {
        if(p==NULL) /*no nodes in linked list*/
        {
            t->prev=NULL;
            t->next=NULL;
            head=t;
        }
        else
        {
            /*else case of zero index*/
        t->prev=NULL;
        t->next=p;
        p->prev=t;
        head=t;
        }
    }
   else
   {
        /*other valid indexes*/
    int i;
    for(i=1;i<=(index-1);i++)
    {
        p=p->next;
    }
    t->prev=p;
    t->next=p->next;
    if(p->next!=NULL) /*this assignment has to be conditional*/
    {
        p->next->prev=t;
    }
    p->next=t;
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
