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
    void display(struct node*);
    int a[]={1,2,3,4,5};
    head=create(a,5);
    printf("the contents of the linked list are: \n");
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
void display(struct node* head)
{
    struct node *p;
    p=head;
    if(p!=NULL)
    {
        printf("%d \n",p->data);
        display(p->next);
    }
}
