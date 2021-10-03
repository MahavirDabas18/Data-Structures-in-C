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
    struct node* circreate(int a[],int);
    void display(struct node*);
    int a[]={10,20,30,40,50};
    head=circreate(a,5);
    printf("the elements of the circular linked list are: \n");
    display(head);
}
struct node* circreate(int a[],int n)
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
    do
    {
        printf("%d \n",p->data);
        p=p->next;
    }while(p!=head);
}
