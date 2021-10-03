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
    int size;
    int top;
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
struct tnode* treecreate(int); /*takes in number of nodes*/
void inorder(struct tnode*);
int main()
{
    struct tnode* root;
    int num;
    printf("enter the number of nodes in the binary tree: \n");
    scanf("%d",&num);
    root=treecreate(num);
    printf("the inorder traversal of the binary tree is: \n");
    inorder(root);
}
struct queue* queuecreate(int x)
{
    struct queue* q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=0;
    q->size=x;
    q->a=(struct tnode**)malloc(x*sizeof(struct tnode*)); /*initialization*/
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
    st->size=x;
    st->top=-1;
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
    q=queuecreate(size+10); /*sufficiently large queue is created*/
    root=(struct tnode*)malloc(sizeof(struct tnode));
    int x;
    printf("enter the value of root: \n");
    scanf("%d",&x);
    root->data=x;
    root->lchild=root->rchild=NULL; /*root node created*/
    enqueue(q,root); /*address of root node enqueued*/
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
            p->lchild=t; /*link between parent and child has been created*/
            enqueue(q,t); /*enqueued the address of the newest node*/
        }
        printf("enter the right child of %d: \n",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct tnode*)malloc(sizeof(struct tnode));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t; /*link between parent and child has been created*/
            enqueue(q,t); /*enqueued the address of the newest node*/
        }
    }
    return root; /*the address of the root node is returned*/
}
void inorder(struct tnode* root)
{
    struct tnode* t;
    t=root;
    struct stack* st;
    st=stackcreate(100);
    while(!(t==NULL && stackisempty(st)==1))
    {
        if(t!=NULL)
        {
            push(st,t);
            t=t->lchild;
        }
        else
        {
            t=pop(st);
            printf("%d ",t->data);
            t=t->rchild;
        }
    }
}
