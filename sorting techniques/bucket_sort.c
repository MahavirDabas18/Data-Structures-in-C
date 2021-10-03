#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct node
{
    int data;
    struct node* next;
};
int FindMax(int a[],int n)
{
    int i;
    int max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
void InsertBin(struct node** bin,int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(bin[x]==NULL) /*empty bin for that index*/
    {
        bin[x]=t;
    }
    else
    {
        struct node* p;
        p=bin[x];
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}
int DeleteBin(struct node** bin,int x)
{
    struct node* t;
    struct node* p;
    t=bin[x];
    p=t->next;
    bin[x]=p;
    int value=t->data;
    free(t);
    return value;
}
void BinSort(int a[],int n)
{
    int max=FindMax(a,n);
    struct node* *bin=(struct node**)malloc((max+1)*sizeof(struct node*));
    int i;
    for(i=0;i<=max;i++)
    {
        bin[i]=NULL;
    }
    for(i=0;i<n;i++)
    {
        InsertBin(bin,a[i]);
    }
    i=0;
    int j=0;
    while(i<=max)
    {
        if(bin[i]==NULL)
        {
            i++;
        }
        else
        {
            int x=DeleteBin(bin,i);
            a[j]=i;
            j++;
        }
    }
}
void Display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    BinSort(a,n);
    printf("the sorted array is: \n");
    Display(a,n);
}
