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
    if(t==NULL) /*empty tree*/
    {
        return t;
    }
    /*tree is not empty*/
    while(t!=NULL)
    {
        if(t->data==key)
        {
            break;
        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else
        {
            t=t->lchild;
        }
    }
    /*if it has reached here it means that either it was broken because key was found or because t became null*/
    return t;
}
struct tnode* insert(struct tnode* t,int key)
{
    struct tnode *p,*q;
    if(t==NULL) /*if the tree is empty*/
    {
        p=(struct tnode*)malloc(sizeof(struct tnode));
        p->lchild=p->rchild=NULL;
        p->data=key;
        return p; /*the first node is created and returned*/
    }
    /*case of non empty tree*/
    /*we check if the key is already present because duplicates are not allowed in BST*/
    if(search(t,key)!=NULL)
    {
        return NULL;
    }
    /*key is not already present*/
    p=t; /*head pointer*/
    q=NULL; /*tail pointer*/
    while(p!=NULL)
    {
        if(key>p->data)
        {
            q=p;
            p=p->rchild;
        }
        else
        {
            q=p;
            p=p->lchild;
        }
    }
    /*now p points at null and r points to the prev node*/
    p=(struct tnode*)malloc(sizeof(struct tnode));
    p->lchild=p->rchild=NULL;
    p->data=key; /*the new node is created*/
    if(p->data>q->data)
    {
        q->rchild=p; /*link between parent and child created*/
    }
    else
    {
        q->lchild=p; /*link between parent and child created*/
    }
    return t; /*the head of the tree is returned*/
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
    printf("the inorder traversal of the binary search tree is: \n");
    inorder(root);
}
