#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node* next;
};
struct node *head;
int main()
{
    int x;
    struct node *t1,*t2;
    struct node* create(int a[],int);
    void display(struct node*);
    struct node* concat(struct node*,struct node*);
    int isloop(struct node*);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    t1=head->next->next; /*points at 3*/
    t2=head->next->next->next->next; /*points at 5*/
    t2=t1; /*5 points at 3 and thus loop is created*/
    x=isloop(head);
    x==1?printf("the  linked list has a loop \n"):printf("the linked list is linear");

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
    return p;

}
int isloop(struct node* f)
{
    struct node *p,*q;
    p=q=f;
    while(p!=q && p!=NULL && q!=NULL)
    {
        p=p->next;
        q=q->next;
        if(q!=NULL) /*we check this condition for q because if list is linear it will reach null first as it moves at 2x rate and there is no point
            of incrementing anymore*/
        {
            q=q->next;
        }
    }
    if(p==q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
