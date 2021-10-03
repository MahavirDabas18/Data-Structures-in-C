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
    void display(struct node*);
    int count(struct node*);
    int del(struct node*,int);
    int a[]={1,2,3,4,5};
    head=create(a,5);
    display(head);
    x=del(head,1);
    printf("the deleted element is: %d \n",x);
    display(head);
    x=del(head,4); /*now 4 elements in linked list with index 4 carrying the last element i.e 5*/
    printf("the deleted element is: %d \n",x);
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
int del(struct node* p,int index)
{
    int i,x;
    struct node *q=NULL; /*FOLLOWER POINTER*/
    if(index<1 || index>count) /*case of invalid index*/
    {
        return;
    }
    /*else case*/
    if(index==1) /*special case of first element being deleted*/
    {
        head=head->next;
        x=p->data;
        free(p);
        return x;
    }
    else /*normal case*/
    {
        for(i=1;i<=(index-1);i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}
