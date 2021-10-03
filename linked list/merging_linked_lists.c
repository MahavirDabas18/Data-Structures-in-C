#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node* next;
};
struct node *head1,*head2,*head3;
int main()
{
    struct node* create(int a[],int);
    void display(struct node*);
    struct node* merge(struct node*,struct node*);
    int a[]={10,20,30,40,50};
    int b[]={5,15,25,35,45};
    head1=create(a,5);
    head2=create(b,5);
    head3=merge(head1,head2);
    printf("the merged linked list: \n");
    display(head3);

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
struct node* merge(struct node* first,struct node* second)
{
    struct node *third,*last;
    if(first->data<second->data) /*first element decision*/
    {
        third=first;
        first=first->next;
        last=third;
        last->next=NULL;
    }
    else if(first->data==second->data)
    {
        third=first;
        first=first->next;
        second=second->next;
        last=third;
        last->next=NULL;
    }
    else
    {
        third=second;
        second=second->next;
        last=third;
        last->next=NULL;
    } /*last element retrieved*/
    while(first!=NULL && second!=NULL)
    {
        if(first->data<second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else if(first->data==second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            second=second->next;
            last->next=NULL;
        }
        else
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first!=NULL) /*for rest of the elements of either*/
    {
        last->next=first;
    }
    else
    {
        last->next=second;
    }
    return third;

}


void display(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
