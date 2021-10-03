#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct tnode
{
    struct tnode* lchild;
    int data;
    struct tnode* rchild;
    int height;
};
struct tnode* rsearch(struct tnode* p,int key)
{
    if(p==NULL) /*base case-tree empty or element not found (unsuccessful search)*/
    {
        return NULL;
    }
    if(key>p->data)
    {
        return rsearch(p->rchild,key);
    }
    else if(key<p->data)
    {
        return rsearch(p->lchild,key);
    }
    else /*wohoo,found you*/
    {
        return p;
    }
}
int GetHeight(struct tnode* p)
{
    if(p==NULL) /*base case*/
    {
        return 0;
    }
    /*recursive case*/
    int x,y;
    x=GetHeight(p->lchild);
    y=GetHeight(p->rchild);
    if(x>y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
}
int BalanceFactor(struct tnode* p)
{
    int x,y;
    x=GetHeight(p->lchild);
    y=GetHeight(p->rchild);
    return (x-y);
}
struct tnode* LLRotate(struct tnode* p)
{
    struct tnode* pl=p->lchild;
    struct tnode* pll=pl->lchild;
    struct tnode* plr=pl->rchild; /*trackers*/
    pl->rchild=p;
    p->lchild=plr; /*rotation*/
    pl->height=GetHeight(pl);
    p->height=GetHeight(p); /*height updated*/
    /*pl is the new root and is thus returned*/
    return pl;
}
struct tnode* LRRotate(struct tnode* p)
{
    struct tnode* pl=p->lchild;
    struct tnode* plr=pl->rchild;
    struct tnode* plrl=plr->lchild;
    struct tnode* plrr=plr->rchild; /*trackers*/
    plr->lchild=pl;
    plr->rchild=p;
    pl->rchild=plrl;
    p->lchild=plrr; /*rotation*/
    plr->height=GetHeight(plr);
    pl->height=GetHeight(pl);
    p->height=GetHeight(p); /*height updated*/
    /*plr is the new root*/
    return plr;
}
struct tnode* RRRotate(struct tnode* p)
{
    struct tnode* pr=p->rchild;
    struct tnode* prr=pr->rchild;
    struct tnode* prl=pr->lchild; /*trackers*/
    pr->lchild=p;
    p->rchild=prl; /*rotation*/
    pr->height=GetHeight(pr);
    p->height=GetHeight(p); /*height updated*/
    /*pr is the root node now*/
    return pr;
}
struct tnode* RLRotate(struct tnode* p)
{
    struct tnode* pr=p->rchild;
    struct tnode* prl=pr->lchild;
    struct tnode* prll=prl->lchild;
    struct tnode* prlr=prl->rchild; /*trackers*/
    prl->lchild=p;
    prl->rchild=pr;
    p->rchild=prll;
    pr->lchild=prlr; /*rotation*/
    p->height=GetHeight(p);
    pr->height=GetHeight(pr);
    prl->height=GetHeight(prl); /*height updated*/
    /*prl is the new root*/
    return prl;
}
struct tnode* rinsert(struct tnode* p,int key)
{
    if(p==NULL) /*base case-tree is empty or we have reached the end where we need to insert*/
    {
        struct tnode* t=(struct tnode*)malloc(sizeof(struct tnode));
        t->data=key;
        t->rchild=t->lchild=NULL;
        t->height=1;
        return t; /*this address is returned which will be updated as the right/left child later in the recursive call*/
    }
    if(rsearch(p,key)!=NULL) /*it means that the element to be inserted is already present but duplicates are not allowed in BST*/
    {
        return NULL;
    }
    if(key>p->data)
    {
        p->rchild=rinsert(p->rchild,key);
    }
    else
    {
        p->lchild=rinsert(p->lchild,key);
    }
    p->height=GetHeight(p); /*height of p will change and is thus updated-updating heights of other nodes will be taken care of by the recursive call*/

    /*IMBALANCE CHECK TO DECIDE WHICH ROTATION-we'll check for the root being imbalanced in the input n case all other nodes will be checked for
    being imbalanced and rotated automatically by the recursion in the input n-1 case*/
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
    {
        return LLRotate(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
    {
        return LRRotate(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
    {
        return RRRotate(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
    {
        return RLRotate(p);
    }
    else
    {
        return p; /*return unchanged root*/
    }
}
void inorder(struct tnode* t)
{
    if(t!=NULL)
    {
        inorder(t->lchild);
        printf("%d ",t->data);
        inorder(t->rchild);
    }
}
int main()
{
    struct tnode* root=NULL;
    root = rinsert(root, 10);
    root = rinsert(root, 20);
    root = rinsert(root, 30);
    root = rinsert(root, 40);
    root = rinsert(root, 50);
    root = rinsert(root, 25);
    printf("the inorder of the AVL tree is: \n");
    inorder(root);
}
