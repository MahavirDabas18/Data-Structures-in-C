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
/*functions of binary tree*/
struct tnode* treecreate(int);
void levelorder(struct tnode*);
int main()
{
    int num;
    struct tnode* root;
    printf("enter the number of nodes in the binary tree: \n");
    scanf("%d",&num);
    root=treecreate(num);
    printf("the level order traversal of the binary tree is: \n");
    levelorder(root);
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
void levelorder(struct tnode* root)
{
    struct tnode* t=root;
    struct queue* q;
    q=queuecreate(100);
    enqueue(q,t); /*we just have to enqueue the first address of the root node*/
    while(queueisempty(q)!=1)
    {
        t=dequeue(q);
        printf("%d ",t->data); /*the data for the node is printed*/
        if(t->lchild!=NULL)
        {
            enqueue(q,t->lchild); /*left child enqueued if not null*/
        }
        if(t->rchild!=NULL)
        {
            enqueue(q,t->rchild); /*right child enqueued if not null*/
        }
    }
}
