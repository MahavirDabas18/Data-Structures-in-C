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
int GetHeight(struct tnode* t)
{
    if(t==NULL) /*base case=empty tree*/
    {
        return 0;
    }
    int x,y;
    x=GetHeight(t->lchild);
    y=GetHeight(t->rchild);
    return (x+y+1);
}
int BalanceFactor(struct tnode* t)
{
    int x,y;
    x=GetHeight(t->lchild);
    y=GetHeight(t->rchild);
    return (x-y);
}
struct tnode* rsearch(struct tnode* t,int key)
{
    if(t==NULL) /*base case-either tree is empty or we have reached the end (unsuccessful search)*/
    {
        return NULL;
    }
    if(key>t->data)
    {
        return rsearch(t->rchild,key);
    }
    else if(key<t->data)
    {
        return rsearch(t->lchild,key);
    }
    else  /*found you!!!*/
    {
        return t;
    }
}
struct tnode* minimum(struct tnode* t)
{
    if(t==NULL) /*empty tree*/
    {
        return NULL;
    }
    while(t->lchild!=NULL)
    {
        t=t->lchild;
    }
    return t;
}
struct tnode* LLRotate(struct tnode* t)
{
    struct tnode* tl=t->lchild;
    struct tnode* tll=tl->lchild;
    struct tnode* tlr=tl->rchild; /*trackers*/
    tl->rchild=t;
    t->lchild=tlr; /*rotation*/
    tl->height=GetHeight(tl);
    t->height=GetHeight(t); /*height updated*/
    /*tl is the new root*/
    return tl;
}
struct tnode* LRRotate(struct tnode* t)
{
    struct tnode* tl=t->lchild;
    struct tnode* tlr=tl->rchild;
    struct tnode* tlrl=tlr->lchild;
    struct tnode* tlrr=tlr->rchild; /*trackers*/
    tlr->lchild=tl;
    tlr->rchild=t;
    tl->rchild=tlrl;
    t->lchild=tlrr; /*rotation*/
    tlr->height=GetHeight(tlr);
    t->height=GetHeight(t);
    tl->height=GetHeight(tl); /*height updated*/
    /*tlr is the new root*/
    return tlr;
}
struct tnode* RRRotate(struct tnode* t)
{
    struct tnode* tr=t->rchild;
    struct tnode* trr=tr->rchild;
    struct tnode* trl=tr->lchild; /*trackers*/
    tr->lchild=t;
    t->rchild=trl; /*rotation*/
    tr->height=GetHeight(tr);
    t->height=GetHeight(t); /*height updated*/
    /*tr is the new root*/
    return tr;
}
struct tnode* RLRotate(struct tnode* t)
{
    struct tnode* tr=t->rchild;
    struct tnode* trl=tr->lchild;
    struct tnode* trll=trl->lchild;
    struct tnode* trlr=trl->rchild; /*trackers*/
    trl->lchild=t;
    trl->rchild=tr;
    t->rchild=trll;
    tr->lchild=trlr; /*rotation*/
    trl->height=GetHeight(trl);
    t->height=GetHeight(t);
    tr->height=GetHeight(tr); /*height updated*/
    /*trl is the new node*/
    return trl;
}
struct tnode* rinsert(struct tnode* t,int key)
{
    if(t==NULL) /*base case-either tree is empty or we have reached the end where we need to insert*/
    {
        struct tnode* p=(struct tnode*)malloc(sizeof(struct tnode));
        p->lchild=p->rchild=NULL;
        p->height=1;
        p->data=key;
        return p;
    }
    if(rsearch(t,key)!=NULL)
    {
        return NULL; /*we are trying to insert a key which is already there,but no duplicates in BST*/
    }
    if(key>t->data)
    {
        t->rchild=rinsert(t->rchild,key);
    }
    else
    {
        t->lchild=rinsert(t->lchild,key);
    }
    t->height=GetHeight(t); /*height of t is updated after insertion*/
    /*after updating height of t we check for t being imbalanced and if imbalanced we perform the required rotation*/
    if(BalanceFactor(t)==2 && BalanceFactor(t->lchild)==1)
    {
        return LLRotate(t);
    }
    else if(BalanceFactor(t)==2 && BalanceFactor(t->lchild)==-1)
    {
        return LRRotate(t);
    }
    else if(BalanceFactor(t)==-2 && BalanceFactor(t->rchild)==-1)
    {
        return RRRotate(t);
    }
    else if(BalanceFactor(t)==-2 && BalanceFactor(t->rchild)==1)
    {
        return RLRotate(t);
    }
    else /*the node is baalnced so we return it as it is*/
    {
        return t;
    }
}
struct tnode* rdelete(struct tnode* t,int key)
{
    if(t==NULL) /*base case-the tree is empty or we have reached the end (unsuccessful search)*/
    {
        return NULL;
    }
    if(key>t->data)
    {
        t->rchild=rdelete(t->rchild,key);
    }
    else if(key<t->data)
    {
        t->lchild=rdelete(t->lchild,key);
    }
    else /*wohooo found you-we are on the node to be deleted*/
    {
        /*case 1-no children*/
        if(t->lchild==NULL && t->rchild==NULL)
        {
            free(t);
            return NULL;
        }
        /*case 2-one child*/
        else if(t->lchild==NULL)
        {
            struct tnode* p=t->rchild;
            free(t);
            return p;
        }
        else if(t->rchild==NULL)
        {
            struct tnode* p=t->lchild;
            free(t);
            return p;
        }
        /*case 3-2 children*/
        else
        {
            struct tnode* p=minimum(t->rchild);
            t->data=p->data;
            t->rchild=rdelete(t->rchild,t->data); /*reduces to case 1 or case 2, we don't return anything in this case as the returning is done by
            case 1 and case 2*/
        }
    }
    /*the height of t changes upon  deletion so we update it*/
    t->height=GetHeight(t);
    /*after updating height of p,we check for it's balance factor and if imbalanced we perform the required rotation*/
    /*case L1*/
    if(BalanceFactor(t)==2 && BalanceFactor(t->lchild)==1)
    {
        return LLRotate(t);
    }
    /*case L-1*/
    else if(BalanceFactor(t)==2 && BalanceFactor(t->lchild)==-1)
    {
        return LRRotate(t);
    }
    /*case L0*/
    else if(BalanceFactor(t)==2 && BalanceFactor(t->lchild)==0)
    {
        return LLRotate(t);
    }
    /*case R1*/
    else if(BalanceFactor(t)==-2 && BalanceFactor(t->rchild)==1)
    {
        return RLRotate(t);
    }
    /*case R-1*/
    else if(BalanceFactor(t)==-2 && BalanceFactor(t->rchild)==-1)
    {
        return RRRotate(t);
    }
    /*case R0*/
    else if(BalanceFactor(t)==2 && BalanceFactor(t->rchild)==0)
    {
        return RRRotate(t);
    }
    /*the node is completely balanced and we return it as it is*/
    else
    {
        return t;
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
    root=rinsert(root,10);
    root=rinsert(root,20);
    root=rinsert(root,30);
    root=rinsert(root,25);
    root=rinsert(root,28);
    root=rinsert(root,27);
    root=rinsert(root,5);
    printf("the inorder of the tree before deletion is: \n");
    inorder(root);
    printf("\n");
    root=rdelete(root,30);
    root=rdelete(root,25);
    root=rdelete(root,28);
    printf("the inorder of the tree after deletion is: \n");
    inorder(root);
}
