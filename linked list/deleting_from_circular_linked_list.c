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
    int count(struct node*);
    void del(struct node*,int);
    int a[]={10,20,30,40,50};
    head=create(a,5);
    printf("the original linked list: \n");
    display(head);
    del(head,1);
    del(head,4);
    printf("the linked list after deletion is: \n");
    display(head);

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
    last->next=p;
    return p;

}
void display(struct node* p)
{
    struct node* q;
    q=p;
    do
    {
        printf("%d \n",p->data);
        p=p->next;
    }while(p!=q);
}
int count(struct node* p)
{
    struct node *q=p;
    int c=0;
    do
    {
        c++;
        p=p->next;
    }while(p!=q);
    return c;
}
void del(struct node* p,int index)
{int x;
    if(index<1 || index>count(p)) /*invalid index*/
    {
        return;
    }
    /*else cases*/
    if(index==1) /*special case*/
    {
        while(p->next!=head) /*to make p point to the last node*/
        {
            p=p->next;
        }
        x=head->data;
        if(head==p) /*case of only one node*/
        {
            free(head);
            head=NULL;
            return x;
        }
        else
        {
            p->next=head->next;
            free(head);
            head=p->next;
            return x;
        }
    }
    /*other valid cases*/
    struct node* q;
    int i;
    for(i=1;i<=(index-2);i++)
    {
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    x=q->data;
    free(q);
    return x;

}
