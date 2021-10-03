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
    void rdisplay(struct node*);
    int a[]={10,20,30,40,50};
    head=circreate(a,5);
    printf("the elements of the circular linked list are: \n");
    rdisplay(head);
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
void rdisplay(struct node* p)
{
    static int flag=0;
    if(p!=head || flag==0)
    {
        flag++;
        printf("%d \n",p->data);
        rdisplay(p->next);
    }
    /*else case*/
    flag=0; /*we have to make flag=0 if the function is called again as flag is static and will take last value if not made zero again*/
}
