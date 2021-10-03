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
{   struct node *p;
    int a[5]={1,2,3,4,5};
    struct node* create(int a[],int);
    struct node* lsearch(struct node*,int);
    void display(struct node*);
    head=create(a,5);
    p=lsearch(head,5);
    printf("the value at the node is: %d \n",p->data);
    display(head);
}
struct node* create(int a[],int n)
{
   struct node *head,*t,*last;
   head=(struct node*)malloc(sizeof(struct node));
   head->data=a[0];
   head->next=NULL;
   last=head;
   int i;
   for(i=1;i<n;i++)
   {
       t=(struct node*)malloc(sizeof(struct node));
       t->data=a[i];
       t->next=NULL;
       last->next=t;
       last=t;
   }
   return head;
}
struct node* lsearch(struct node* p,int key)
{
   struct node *q;
   q=NULL;
   while(p!=NULL)
   {
       if(p->data==key)
       {
           q->next=p->next;
           p->next=head; /*head is globally declared and thus is accessible by the function*/
           head=p; /*now head of the linked list points and p making it the first node*/
           return p;
       }
       q=p;
       p=p->next;

   }
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
