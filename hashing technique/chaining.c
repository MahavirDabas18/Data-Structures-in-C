#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*hash function is h(x)=x%10*/
struct node
{
    int data;
    struct node* next;
};
int hash(int key)
{
    return key%10;
}
void insert(struct node** HT,int key)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=key;
    t->next=NULL;
    int index=hash(key);
    if(HT[index]==NULL) /*nothing linked to the index*/
    {
        HT[index]=t;
    }
    else
    {
        struct node* p=HT[index];
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}
int search(struct node** HT,int key)
{
    int index=hash(key);
    struct node* p;
    p=HT[index];
    while(p!=NULL)
    {
        if(p->data==key)
        {
            return 1;
        }
        else
        {
            p=p->next;
        }
    }
    return 0;
}
int del(struct node** HT,int key)
{
    if(search(HT,key)==1)
    {
        int index=hash(key);
        struct node* p=HT[index];
        int x;
        if(p->data==key) /*the node to be deleted is the first one*/
        {
            HT[index]=HT[index]->next;
            x=p->data;
            free(p);
            return x;
        }
        else
        {
            struct node* q=NULL; /*tail pointer*/
            while(p->data!=key)
            {
                q=p;
                p=p->next;
            }
            int x=p->data;
            q->next=p->next;
            free(p);
            return x;
        }
    }
    else
    {
        return 0;
    }

}
int main()
{
    struct node** HT=(struct node**)malloc(10*sizeof(struct node*));
    int i;
    for(i=0;i<10;i++)
    {
        HT[i]=NULL;
    }
    insert(HT,11);
    insert(HT,12);
    insert(HT,22);
    insert(HT,33);
    insert(HT,44);
    insert(HT,55);
    insert(HT,66);
    insert(HT,77);
    insert(HT,88);
    insert(HT,99);
    search(HT,22)==1?printf("22 is present \n"):printf("22 is not present \n");
    search(HT,66)==1?printf("66 is present \n"):printf("66 is not present \n");
    search(HT,12)==1?printf("12 is present \n"):printf("12 is not present \n");
    del(HT,12);
    printf("after deletion: \n");
    search(HT,12)==1?printf("12 is present \n"):printf("12 is not present \n");

}
