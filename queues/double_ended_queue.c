#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct node
{
    int data;
    struct node* next;
};
struct node *front=NULL,*rear=NULL;
void infront(struct node*,int);
void inrear(struct node*,int);
int outfront(struct node*);
int outrear(struct node*);
void display(struct node*);
int isempty(struct node*);
int isfull(struct node*);
int first(struct node*);
int last(struct node*);
int main()
{
    infront(front,1);
    infront(front,2);
    infront(front,3);
    infront(front,4);
    infront(front,5);
    inrear(rear,6);
    inrear(rear,7);
    inrear(rear,8);
    inrear(rear,9);
    inrear(rear,10);
    printf("the queue is: \n");
    display(front);
    outfront(front);
    outfront(front);
    outrear(front);
    outrear(front);
    printf("the queue now is: \n");
    display(front);
    printf("the first element is: %d \n",first(front));
    printf("the last element is: %d \n",last(rear));
    isempty(front)==1?printf("the list is empty \n"):printf("the list is not empty \n");
    isfull(front)==1?printf("the list is full \n"):printf("the list is not full \n");
}
void infront(struct node* p,int x)
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL) /*heap is full*/
    {
        printf("queue overflow \n");
        return;
    }
    else
    {
        t->data=x;
        if(p==NULL) /*front is null-the queue is empty*/
        {
            t->next=NULL;
            front=rear=t;
        }
        else /*the queue is not empty*/
        {
            t->next=p;
            front=t;
        }

    }
}
void inrear(struct node* p,int x)
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL) /*heap is full*/
    {
        printf("queue overflow \n");
        return;
    }
    else
    {   t->data=x;
        if(p==NULL) /*rear is null-queue is empty*/
        {
            front=rear=t;
            t->next=NULL;
        }
        else /*the queue is not empty*/
        {
            rear->next=t;
            t->next=NULL;
            rear=t;
        }
    }
}
void display(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
int outfront(struct node* p)
{
    if(p==NULL) /*the queue is empty*/
    {
        printf("queue underflow \n");
        return;
    }
    else /*queue is not empty*/
    {
        front=front->next;
        int x=p->data;
        free(p);
        return x;
    }
}
int outrear(struct node* p)
{
    if(p==NULL) /*q is empty*/
    {
        printf("queue underflow \n");
        return;
    }
    else /*queue is not empty*/
    {
        struct node* q;
        while(p->next!=NULL)
        {
            q=p; /*will point at second last node*/
            p=p->next;
        }
        int x=p->data;
        q->next=NULL;
        rear=q;
        free(p);
        return x;
    }
}
int first(struct node* p)
{
    if(p==NULL) /*empty queue*/
    {
        printf("the queue is empty \n");
        return;
    }
    else
    {
        return p->data;
    }
}
int last(struct node* p)
{
    if(p==NULL) /*empty queue*/
    {
        printf("the queue is empty \n");
        return;
    }
    else
    {
        return p->data;
    }
}
int isempty(struct node* p)
{
    if(p==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct node* p)
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL) /*heap is full and thus queue is full*/
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
