#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node* next;
};
int main()
{   struct node *head,*p;
    int a[5]={1,2,3,4,5};
    struct node* create(int a[],int);
    struct node* lsearch(struct node*,int);
    head=create(a,5);
    p=lsearch(head,5);
    printf("the value at the node is: %d \n",p->data);
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
   while(p!=NULL)
   {
       if(p->data==key)
       {
           return p;
       }
       p=p->next;
   }
   return 0;
}
