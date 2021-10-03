#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct stack /*we are defining the stack structure*/
{
    int top;
    int size;
    struct tnode* *a; /*the array of the stack stores addresses of tree node*/
};
struct queue /*queue for creation of tee*/
{
    int size;
    int front;
    int rear;
    struct tnode* *a; /*address of struct tnode will be stored inside the array a*/
};
struct tnode
{
    struct tnode* lchild;
    int data;
    struct tnode* rchild;
};
struct stack* stackcreate(int); /*takes size of the array as input*/ /*stack function begin*/
void push(struct stack *,struct tnode*); /*the value to be pushed is an address of a tree node*/
struct tnode* pop(struct stack*);
int sempty(struct stack*); /*stack function end*/
struct queue* queuecreate(int); /*queue function begin*/
void enqueue(struct queue*,struct tnode*);
struct tnode* dequeue(struct queue*);
int qempty(struct queue*); /*queue function end*/
struct tnode* treecreate(int); /*takes in the number of nodes*/ /*tree function begin*/
void preorder(struct tnode*); /*tree function end*/
int main()
{
    struct tnode* root;
    int x;
    printf("enter the number of nodes in the binary tree: \n");
    scanf("%d",&x);
    root=treecreate(x);
    printf("the preorder traversal of the tree is: \n");
    preorder(root);
}
struct stack* stackcreate(int x)
{
    struct stack* st;
    st=(struct stack*)malloc(sizeof(struct stack));
    st->size=x;
    st->top=-1;
    st->a=(struct tnode**)malloc(st->size*sizeof(struct node*));
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
        printf("stack underflow \n1");
        return -1;
    }
    else
    {
        struct tnode* x;
        x=st->a[st->top];
        st->top--;
        return x;
    }
}
int sempty(struct stack* st)
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
struct queue* queuecreate(int x)
{
    struct queue* q;
    q=(struct queue*)malloc(sizeof(struct queue)); /*queue created*/
    q->front=q->rear=0;
    q->size=x;
    q->a=(struct tnode**)malloc(q->size*sizeof(struct tnode*)); /*queue initialized*/
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
    if(q->rear==q->front)
    {
        printf("queue underflow \n");
        return;
    }
    else
    {
        struct tnode* x;
        q->front=(q->front+1)%q->size;
        x=q->a[q->front];
        return x;
    }
}
int qempty(struct queue* q)
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
struct tnode* treecreate(int x)
{
    struct tnode *r,*p,*t;
    struct queue *q;
    q=queuecreate(x+15); /*we create an array with capacity sufficiently more the number of nodes*/
    r=(struct tnode*)malloc(sizeof(struct tnode)); /*root has been created*/
    int y;
    printf("enter root value: \n");
    scanf("%d",&y);
    r->data=y;
    r->lchild=r->rchild=NULL; /*root has been initialized*/
    enqueue(q,r);
    while(qempty(q)!=1)
    {
        p=dequeue(q);
        printf("enter left child of %d: \n",p->data);
        scanf("%d",&y);
        if(y!=-1)
        {
            t=(struct tnode*)malloc(sizeof(struct tnode));
            t->data=y;
            t->rchild=t->lchild=NULL;
            p->lchild=t; /*link has been created between parent and child*/
            enqueue(q,t); /*address added to queue*/
        }
        printf("enter right child of %d: \n",p->data);
        scanf("%d",&y);
        if(y!=-1)
        {
            t=(struct tnode*)malloc(sizeof(struct tnode));
            t->data=y;
            t->rchild=t->lchild=NULL;
            p->rchild=t; /*link has been created between parent and child*/
            enqueue(q,t); /*address added to queue*/
        }
    }
    return r; /*the address of the root node is returned*/

}
void preorder(struct tnode* root)
{
    struct tnode* t;
    t=root;
    struct stack* st;
    st=stackcreate(100);
    while(!(t==NULL && sempty(st)==1))
    {
        if(t!=NULL)
        {
            printf("%d ",t->data);
            push(st,t);
            t=t->lchild;
        }
        else
        {
            t=pop(st);
            t=t->rchild;
        }
    }
}










