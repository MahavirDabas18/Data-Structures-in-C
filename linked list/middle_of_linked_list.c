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
    struct node *p,*q;
    struct node* create(int a[],int);
    int middle(struct node*);
    void display(struct node*);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    printf("the linked list is: \n");
    display(head);
    printf("the element at the middle of the linked list is: %d \n",middle(head));
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
int middle(struct node *first)
{
    struct node *p,*q;
    p=q=first;
    while(q!=NULL)
    {
        q=q->next;
        if(q!=NULL)
        {
            q=q->next;
        }
        if(q!=NULL)
        {
            p=p->next;
        }
    }
    return p->data;
}
void display(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
