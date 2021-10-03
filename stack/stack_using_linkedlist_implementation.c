#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node* next;
};
struct node* top=NULL; /*initialized with null so that stack is empty at first*/
int main()
{
    void push(struct node*,int);
    void display(struct node*);
    int pop(struct node*);
    int peak(struct node*,int);
    int stacktop(struct node*);
    int isempty(struct node*);
    push(top,1);
    push(top,2);
    push(top,3);
    push(top,4);
    push(top,5);
    pop(top);
    pop(top);
    printf("the stack is: \n");
    display(top);
    printf("the element at the second position is: %d \n",peek(top,2));
    printf("the element at the top of the stack is: %d \n",stacktop(top));
    isempty==1?printf("the stack is empty \n"):printf("the stack is not empty \n");
}
void push(struct node* st,int x)
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("stack overflow \n");
        return ;
    }
    else
    {
        t->data=x;
        t->next=st;
        top=t;
    }
}
int pop(struct node* st)
{
    if(st==NULL)
    {
        return;
    }

    else
    {
        int x;
        struct node* p;
        p=st;
        top=top->next;
        x=p->data;
        free(p);
        return x;
    }
}
int peek(struct node* st,int pos)
{
    struct node* p=st;
    int i;
    for(i=1;p!=NULL && i<=(pos-1);i++)
    {
        p=p->next;
    }
    if(p!=NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}
int stacktop(struct node* st)
{
    if(st==NULL)
    {
        return -1;
    }
    else
    {
        return st->data;
    }
}
int isempty(struct node* st)
{
    if(st==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(struct node *st)
{
    while(st!=NULL)
    {
        printf("%d \n",st->data);
        st=st->next;
    }
}
