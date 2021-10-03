#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node* next;
};
int main()
{
    struct node* head;
    struct node* create(int a[],int);
    int count(struct node*);
    int sum(struct node*);
    int a[]={1,2,3,4,5};
    head=create(a,5);
    printf("the number of nodes in the linked list are: %d \n",count(head));
    printf("the sum of all elements in the linked lost are: %d \n",sum(head));
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
int count(struct node* p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}
int sum(struct node *p)
{
   int sum=0;
   while(p!=NULL)
   {
       sum+=p->data;
       p=p->next;
   }
   return sum;
}
