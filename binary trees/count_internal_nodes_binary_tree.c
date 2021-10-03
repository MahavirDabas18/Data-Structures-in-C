#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct queue /*we will implement a circular queue*/
{
    int size;
    int front;
    int rear;
    struct tnode* *a; /*the first pointer is for defining the types of values, the second pointer is for array creation*/

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
/*functions of tree*/
struct tnode* treecreate(int);
void preorder(struct tnode*);
int countinternal(struct tnode*);
int main()
{
    struct tnode* root;
    int num;
    printf("enter the number of nodes in the binary tree: \n");
    scanf("%d",&num);
    root=treecreate(num);
    printf("the preorder traversal of the binary tree is: \n");
    preorder(root);
    printf("\n");
    printf("the number of internal nodes in the tree: %d \n",countinternal(root));
}
struct queue* queuecreate(int x)
{
    struct queue* q;
    q=(struct queue*)malloc(sizeof(struct queue)); /*creation*/
    q->front=q->rear=0;
    q->size=x;
    q->a=(struct tnode* *)malloc(q->size*sizeof(struct tnode*)); /*initialization*/
    return q;
}
void enqueue(struct queue* q,struct tnode* x)
{
    if((q->rear+1)%q->size==q->front) /*full condition*/
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
    if(q->front==q->rear) /*empty condition*/
    {
        printf("queue underflow \n");
        return;
    }
    else
    {
        struct tnode* x;
        q->front=(q->front+1)%q->size;
        x=q->a[q->front]; /*front is empty, we take x to be returned after moving front*/
        return x;
    }
}
int queueisempty(struct queue* q)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    return 0;
}
struct tnode* treecreate(int size)
{
    struct tnode *r,*p,*t;
    struct queue *q;
    q=queuecreate(size+15); /*this big array is sufficient*/
    r=(struct tnode*)malloc(sizeof(struct tnode)); /*root creation*/
    int x;
    printf("enter the value of root node: \n");
    scanf("%d",&x);
    r->data=x;
    r->lchild=r->rchild=NULL; /*root initialization*/
    /*the first root node has been created which will be ultimately returned*/
    enqueue(q,r); /*the root node address has been added to the queue- the initial step for tree creation is over*/
    while(queueisempty(q)!=1) /*loop will stop when the queue has become empty*/
    {
        p=dequeue(q);
        printf("enter the left child of %d: \n",p->data); /*case of left child*/
        scanf("%d",&x);
        if(x!=-1) /*-1 will be case of no left child*/
        {
            t=(struct tnode*)malloc(sizeof(struct tnode)); /*creation*/
            t->data=x;
            t->lchild=t->rchild=NULL; /*initialization*/
            p->lchild=t; /*the link between parent and child is created*/
            enqueue(q,t); /*the address of the newly created left child node has been added to the queue*/
        }
        printf("enter the right child of %d: \n",p->data); /*case of right child*/
        scanf("%d",&x);
        if(x!=-1) /*-1 will be case of no right child*/
        {
            t=(struct tnode*)malloc(sizeof(struct tnode)); /*creation*/
            t->data=x;
            t->lchild=t->rchild=NULL; /*initialization*/
            p->rchild=t; /*the link between parent and child is created*/
            enqueue(q,t); /*the address of the newly created right child node has been added to the queue*/
        }
    }
    return r; /*the first node has been returned to be stored in root*/
}
void preorder(struct tnode* p)
{
    if(p!=NULL)
    {
        printf("%d  ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int countinternal(struct tnode* root)
{
    struct tnode* t=root;
    if(t==NULL) /*base case*/
    {
        return 0;
    }
    else /*if there is a node present*/
    {
        int x,y;
        x=countinternal(t->lchild);
        y=countinternal(t->rchild);
        if(t->lchild!=NULL || t->rchild!=NULL)
        {
            return (x+y+1);
        }
        else
        {
            return (x+y);
        }
    }
}
