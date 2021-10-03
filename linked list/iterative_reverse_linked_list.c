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
    void ireverse(struct node*);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    ireverse(head);
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
void ireverse(struct node* p)
{
    struct node *r,*q;
    r=NULL;
    q=NULL;
    while(p!=NULL)
    {
        r=q; /*sliding begins*/
        q=p;
        p=p->next; /*sliding ends*/
        q->next=r; /*link reversal takes place at q,where q points to r*/
    }
    head=q;
}
void display(struct node* p)
{
    printf("the linked list is: \n");
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
