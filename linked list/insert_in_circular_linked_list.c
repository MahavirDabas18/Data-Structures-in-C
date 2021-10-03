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
    struct node* create(int a[],int);
    void display(struct node*);
    int count(struct node*);
    void insert(struct node*,int,int);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    insert(head,0,0);
    insert(head,6,60);
    display(head);

}
struct node* create(int a[],int n)
{
    struct node *p,*t,*last;
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
    last->next=p;
    return p;

}
void display(struct node* p)
{
    struct node* q;
    q=p;
    do
    {
        printf("%d \n",p->data);
        p=p->next;
    }while(p!=q);
}
int count(struct node* p)
{
    struct node *q=p;
    int c=0;
    do
    {
        c++;
        p=p->next;
    }while(p!=q);
    return c;
}
void insert(struct node *first,int index,int x)
{
    struct node *t,*q;
    if(index<0 || index>count(first)) /*invalid index*/
    {
        return ;
    }
    /*valid index case*/
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(index==0) /*index zero is special case*/
    {
        if(first==NULL) /*there is no node in the linked list*/
        {
            t->next=t;
            head=t;
        }
    else
    {
        q=first;
        while(q->next!=first) /*to make q come on the last node*/
        {
            q=q->next;
        }
        t->next=first;
        q->next=t;
        head=t;
    }

    }
    else
    {
        /*any other index*/
    int i;
    for(i=1;i<=(index-1);i++)
    {
        first=first->next;
    }
    t->next=first->next;
    first->next=t;
    }
}
