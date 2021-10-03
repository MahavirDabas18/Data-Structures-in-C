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
void enqueue(struct node*,struct node*,int);
int dequeue(struct node*);
void display(struct node*);
int isempty(struct node*);
int isfull(struct node*);
int first(struct node*);
int last(struct node*);
int main()
{
    enqueue(front,rear,1);
    enqueue(front,rear,2);
    enqueue(front,rear,3);
    enqueue(front,rear,4);
    enqueue(front,rear,5);
    enqueue(front,rear,6);
    enqueue(front,rear,7);
    enqueue(front,rear,8);
    enqueue(front,rear,9);
    enqueue(front,rear,10);
    printf("the queue is: \n");
    display(front);
    dequeue(front);
    dequeue(front);
    dequeue(front);
    printf("the queue now is: \n");
    display(front);
    printf("the first element is: %d \n",first(front));
    printf("the last element is: %d \n",last(front));
    isempty(front)==1?printf("the queue is empty \n"):printf("the queue is not empty \n");
    isfull(front)==1?printf("the queue is full \n"):printf("the queue is not full \n");

}
void enqueue(struct node* p,struct node* q,int x)
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL) /*the heap is full therefore the queue is full*/
    {
        printf("queue overflow \n");
        return;
    }
    else
    {
        t->data=x;
        t->next=NULL;
        if(p==NULL) /*the list is empty and this is the first node to be inserted*/
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
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
int dequeue(struct node* p)
{
    if(p==NULL) /*the queue is empty*/
    {
        printf("queue underflow \n");
        return;
    }
    else
    {
        front=front->next;
        int x=p->data;
        free(p);
        return x;
    }
}
int first(struct node* p)
{
    if(p==NULL)
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
    if(p==NULL)
    {
        printf("the queue is empty \n");
        return;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
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
    if(t==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
