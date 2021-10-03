#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct tnode
{
    struct tnode* lchild;
    int data;
    struct tnode* rchild;
};
struct tnode* search(struct tnode* t,int key)
{
    if(t==NULL) /*base case-the tree is empty or we have reached the end (unsuccessful search)*/
    {
        return NULL;
    }
    if(key>t->data)
    {
        search(t->rchild,key);
    }
    else if(key<t->data)
    {
        search(t->lchild,key);
    }
    else /*wohoo, found you*/
    {
        return t;
    }
}
struct tnode* insert(struct tnode* t,int key)
{
    if(t==NULL) /*base case-the tree is empty or we have reached the end where the new root has to be inserted*/
    {
        struct tnode* p;
        p=(struct tnode*)malloc(sizeof(struct tnode));
        p->lchild=p->rchild=NULL;
        p->data=key;
        return p;
    }
    if(search(t,key)!=NULL)
    {
        return NULL; /*the key we want to insert is already present but duplicates are not allowed*/
    }
    /*the key is not present, hence can be inserted*/
    if(key>t->data)
    {
        t->rchild=insert(t->rchild,key);
    }
    else
    {
        t->lchild=insert(t->lchild,key);
    }
    return t; /*the parent node is ultimately returned*/
}
struct tnode* minimum(struct tnode* t) /*utility function for finding inorder successor*/
{
    if(t==NULL) /*the tree is empty*/
    {
        return NULL;
    }
    /*non empty tree*/
    while(t->lchild!=NULL)
    {
        t=t->lchild;
    }
}
struct tnode* deleteBST(struct tnode* t,int key)
{
    if(t==NULL) /*base case-the tree is empty or the element to be deleted is not present -unsuccessful search*/
    {
        return NULL;
    }
    if(key>t->data)
    {
        t->rchild=deleteBST(t->rchild,key);
    }
    else if(key<t->data)
    {
        t->lchild=deleteBST(t->lchild,key);
    }
    else /*wohoo found you-this is the node to be deleted,while deleting we have to just return an address which will be sent to the previous call*/
    {
        /*case 1-no child*/
        if(t->lchild==NULL && t->rchild==NULL)
        {
            free(t);
            return NULL;
        }
        /*case 2-only one child*/
        else if(t->lchild==NULL)
        {
            struct tnode* p=t;
            t=t->rchild;
            free(p);
            return t;
        }
        else if(t->rchild==NULL)
        {
            struct tnode* p=t;
            t=t->lchild;
            free(p);
            return t;
        }
        /*case 3-two children-here we don't have to return anything as delete function will be called and it will be reduced to either case 1 or 2*/
        else
        {
            struct tnode* p=minimum(t->rchild);
            t->data=p->data;
            t->rchild=deleteBST(t->rchild,t->data);
        }
    }
    return t; /*the parent node is returned*/
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
    root=insert(root,9);
    insert(root,15);
    insert(root,5);
    insert(root,20);
    insert(root,16);
    insert(root,8);
    insert(root,12);
    insert(root,3);
    insert(root,6);
    printf("the inorder before deletion: \n");
    inorder(root);
    printf("\n");
    root=deleteBST(root,16);
    root=deleteBST(root,8);
    root=deleteBST(root,12);
    printf("the inorder after deletion: \n");
    inorder(root);
}
