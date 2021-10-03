#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node* next;
};
int main()
{struct node *head;
void display(struct node*); /*will take head of the linked list*/
struct node* create(int a[],int); /*returns the pointer to a structure stored in head*/
int a[]={1,2,3,4,5};
head=create(a,5); /*head will get the address of the structure that is linked list*/
display(head);
}
struct node* create(int a[],int n)
{int i;
struct node *head,*last,*t; /*this head is different,it is local to the function and will be returned as it will point to the final linked list*/
head=(struct node*)malloc(sizeof(struct node));
head->data=a[0];
head->next=NULL;
last=head;
for(i=1;i<n;i++)
{
    t=(struct node*)malloc(sizeof(struct node)); /*t will create a new node for the linked list*/
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
}
return head;
}
void display(struct node *head)
{
    struct node *p; /*used to traverse the linked list*/ /*p is a pointer to a structure*/
    printf("the linked list is: \n");
    p=head;
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}
