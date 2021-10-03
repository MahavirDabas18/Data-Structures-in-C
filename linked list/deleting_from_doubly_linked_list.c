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
    int del(struct node*,int);
    int count(struct node*);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    printf("the original linked list: \n");
    display(head);
    del(head,1);
    del(head,4);
    printf("the linked list after deletions: \n");
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
int del(struct node* p,int index)
{
    int x;
    if(index<1 || index>count(p)) /*case of invalid index*/
    {
        return ;
    }
    /*else case*/
    if(index==1)
    {
        x=p->data;
        if(p->next!=NULL)
        {
            p->next->prev=NULL;
        }
        head=p->next;
        free(p);
        return x;
    }
    /*other valid indexes*/
    int i;
    for(i=1;i<=(index-1);i++)
    {
        p=p->next;
    }
    p->prev->next=p->next;
    if(p->next!=NULL)
    {
        p->next->prev=p->prev;
    }
    x=p->data;
    free(p);
    return x;
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
