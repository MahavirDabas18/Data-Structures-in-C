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
    int a[]={1,2,3,4,5};
    struct node* create(int a[],int);
    void display(struct node*);
    void sortinsert(struct node*,int);
    head=create(a,5);
    display(head);
    sortinsert(head,10);
    sortinsert(head,0);
    display(head);
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
void display(struct node* p)
{
    printf("the elements of the linked list are: \n");
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
void sortinsert(struct node* p,int x)
{
    struct node *t,*q; /*q is follower pointer*/
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(p==NULL) /*case when linked list has no elements*/
    {
        t->next=NULL;
        head=t; /*head is globally accessible*/
    }
    /*else condition*/
    while(p!=NULL && p->data<x) /*2 conditions where loop will continue,one of them fails and the loop stops*/
    {
        q=p; /*follower pointer*/
        p=p->next;
    }
    if(p==head) /*case of left most insertion which is a special case,the first element of the linked list is greater than the element to be inserted*/
    {
        t->next=p;
        head=t; /*linked list points on the newly created node*/
    }
    else /*normal insertion technique*/
    {
        t->next=p;
        q->next=t;
    }

}
