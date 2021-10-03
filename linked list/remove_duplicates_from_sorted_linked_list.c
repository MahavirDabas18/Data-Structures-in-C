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
    int sorted(struct node*);
    void remdup(struct node*);
    void display(struct node*);
    int a[]={1,2,2,2,3,4,5,5,5,10,10};
    head=create(a,11);
    x=sorted(head);
    x==0?printf("the list is not sorted \n"):printf("the list is sorted \n");
    remdup(head);
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
int sorted(struct node* p)
{
    int x=-32768; /*smallest possible int value*/
    while(p!=NULL)
    {
        if(p->data<x)
        {
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}
void remdup(struct node* p)
{
    struct node *q; /*this time this pointer will be in front*/
    q=head->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            q=q->next;
            p=p->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void display(struct node* p)
{printf("the elements of the linked list are: \n");
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
