#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct queue
{
    int front;
    int rear;
    int size;
    struct tnode* *a;
};
struct stack
{
    int top;
    int size;
    struct tnode* *a;
};
struct tnode
{
    struct tnode* lchild;
    int data;
    struct tnode* rchild;
};
/*functions of queue*/
struct queue* queuecreate(int);
void enqueue(struct queue*,struct tnode*);
struct tnode* dequeue(struct queue*);
int queueisempty(struct queue*);
/*functions of stack*/
struct stack* stackcreate(int);
void push(struct stack*,struct tnode*);
struct tnode* pop(struct stack*);
int stackisempty(struct stack*);
/*functions of binary tree*/
struct tnode* treecreate(int);
void postorder(struct tnode*);
int main()
{
    int num;
    struct tnode* root;
    printf("enter the number of nodes in the binary tree: \n");
    scanf("%d",&num);
    root=treecreate(num);
    printf("the post order traversal of the binary tree is: \n");
    postorder(root);
}
struct queue* queuecreate(int x)
{
    struct queue* q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=0;
    q->size=x;
    q->a=(struct tnode**)malloc(x*sizeof(struct tnode*)); /*initialized*/
    return q;
}
void enqueue(struct queue* q,struct tnode* x)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("queue overflow \n");
        return;
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->a[q->rear]=x;
    }
}
struct tnode* dequeue(struct queue* q)
{
    if(q->front==q->rear)
    {
        printf("queue underflow \n");
        return;
    }
    else
    {
        q->front=(q->front+1)%q->size;
        struct tnode* x;
        x=q->a[q->front];
        return x;
    }
}
int queueisempty(struct queue* q)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct stack* stackcreate(int x)
{
    struct stack* st;
    st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    st->size=x;
    st->a=(struct tnode**)malloc(x*sizeof(struct tnode*)); /*initialized*/
    return st;
}
void push(struct stack* st,struct tnode* x)
{
    if(st->top==st->size-1)
    {
        printf("stack overflow \n");
        return;
    }
    else
    {
        st->top++;
        st->a[st->top]=x;
    }
}
struct tnode* pop(struct stack* st)
{
    if(st->top==-1)
    {
        printf("stack underflow \n");
        return;
    }
    else
    {
        struct tnode* x;
        x=st->a[st->top];
        st->top--;
        return x;
    }
}
int stackisempty(struct stack* st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct tnode* treecreate(int size)
{
    struct tnode *root,*p,*t;
    struct queue* q;
    q=queuecreate(size+15); /*queue has sufficiently large space to store the nodes*/
    root=(struct tnode*)malloc(sizeof(struct tnode));
    int x;
    printf("enter the root node: \n");
    scanf("%d",&x);
    root->data=x;
    root->lchild=root->rchild=NULL; /*root node has been initialized*/
    enqueue(q,root); /*it has been enqueued*/
    while(queueisempty(q)!=1)
    {
        p=dequeue(q);
        printf("enter the left child of %d: \n",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
           t=(struct tnode*)malloc(sizeof(struct tnode));
           t->data=x;
           t->lchild=t->rchild=NULL;
           p->lchild=t;/*link has been created between parent and child*/
           enqueue(q,t); /*enqueued*/
        }
        printf("enter the right child of %d: \n",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
           t=(struct tnode*)malloc(sizeof(struct tnode));
           t->data=x;
           t->lchild=t->rchild=NULL;
           p->rchild=t;/*link has been created between parent and child*/
           enqueue(q,t); /*enqueued*/
        }
    }
    return root; /*the root node has been returned*/
}
void postorder(struct tnode* root)
{
    struct tnode* t=root;
    struct stack *st1; /*for storing address of nodes so that we can go back to them after exploring one side*/
    struct stack* st2; /*to store value of addresses of nodes instead of printing their values*/
    st1=stackcreate(100);
    st2=stackcreate(100); /*both the stacks have been created*/
    while(!(t==NULL && stackisempty(st1)==1))
    {
        if(t!=NULL)
        {
            push(st2,t); /*instead of printing we push the value in stack 2*/
            push(st1,t); /*address stored in stack 1 to return to this node after exploring it's right child*/
            t=t->rchild;
        }
        else /*when t becomes null means we have explored the right side of the most previous node, so time to pop reach it and explore it's left side*/
        {
            t=pop(st1);
            t=t->lchild;
        }
    }
    while(stackisempty(st2)!=1) /*now values of stack 2 are popped and printed in that order to get postorder traversal*/
    {
        t=pop(st2);
        printf("%d ",t->data);
    }
}
