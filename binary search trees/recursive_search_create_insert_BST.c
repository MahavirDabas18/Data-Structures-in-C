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
    if(t==NULL)
    {
        return NULL; /*case of unsuccessful search*/
    }
    else /*other case*/
    {
        if(t->data==key)
        {
            return t;
        }
        else if(key>t->data)
        {
            return search(t->rchild,key);
        }
        else
        {
            return search(t->lchild,key);
        }
    }

}
struct tnode* insert(struct tnode* t,int key)
{
    if(t==NULL) /*base case*/
    {
        struct tnode* t;
        t=(struct tnode*)malloc(sizeof(struct tnode));
        t->lchild=t->rchild=NULL;
        t->data=key;
        return t; /*the first node is created and returned,the root is returned*/
    }
    /*case when binary tree is not empty*/
    /*first we search for the element, because duplicates are not allowed*/
    if(search(t,key)!=NULL)
    {
        return NULL;
    }
    /*key is not present and it can be inserted*/
    if(key>t->data)
    {
        t->rchild=insert(t->rchild,key); /*the function will insert it in the right subtree and return it's address which is updated*/
    }
    else
    {
        t->lchild=insert(t->lchild,key); /*the function will insert it in the left subtree and return it's address which is updated*/
    }
    return t; /*the root of the tree is returned*/
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
    printf("the inorder  of the binary search tree is: \n");
    inorder(root);
}
