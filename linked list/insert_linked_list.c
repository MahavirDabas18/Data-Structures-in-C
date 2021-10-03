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
    void insert(struct node*,int,int);
    int a[]={1,2,3,4,5};
    head=create(a,5);
    insert(head,0,0);
    display(head);
}
struct node* create(int a[],int n)
{struct node *p,*t,*last;
int i;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=a[0];
    p->next=NULL;
    last=p;
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

void display(struct node* p)
{struct node* a;
a=p;
    printf("the elements  of the linked list are: \n");
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
void insert(struct node* p,int index,int x)
{struct node *t;
int i;
    if(index<0 || index>count(p)) /*invalid index*/
    {
        return;
    }
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(index==0)
    {
        t->next=head;
        head=t;
    }
    else
    {
      for(i=1;i<=(index-1);i++)
      {
          p=p->next;
      }
      t->next=p->next;
      p->next=t;
    }
}
