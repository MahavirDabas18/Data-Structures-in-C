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
    void reverse(struct node*);
    int count(struct node*);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    printf("the original linked list: \n");
    display(head);
    reverse(head);
    printf("the linked list after reversal: \n");
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
void reverse(struct node* p)
{
    struct node *t;
    while(p!=NULL)
    {
        if(p->next==NULL) /*checking this before swapping because it is the condition of the last node*/
        {
            head=p;
        }
        /*swapping*/
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        /*swapping completed, now to move on the next node in original list we have to go to previous of p*/
        p=p->prev;
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
