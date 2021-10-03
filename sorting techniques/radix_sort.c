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
    int max=a[0];
    int i;
    for(i=0;i<n;i++)
    {
        if(a[0]>max)
        {
            max=a[i];
        }
    }
    return max;
}
void InsertBin(struct node** bin,int key,int pass)
/*in bucket sort we only needed the bin and key to insert, but in radix sort we would also need the pass number so as to deduce in which bin the
key would be thrown into*/
{
    int k=pow(10,pass-1);
    int index=(key/k)%10; /*this will store the index in which the  key will be thrown into*/
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=key;
    t->next=NULL;
    if(bin[index]==NULL)
    {
        bin[index]=t;
    }
    else
    {
        struct node* p=bin[index];
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}
int DeleteBin(struct node** bin,int index) /*will take the bin and the index from which deletion is to be done*/
{
    struct node* p=bin[index];
    bin[index]=p->next;
    int x=p->data;
    free(p);
    return x;
}
int FindDigits(int x)
{
    int d=0;
    while(x!=0)
    {
        x=x/10;
        d++;
    }
    return d;
}
void RadixSort(int a[],int n)
{
    int max=FindMax(a,n);
    struct node* *bin=(struct node**)malloc(10*sizeof(struct node));
    int i;
    for(i=0;i<10;i++)
    {
        bin[i]=NULL;
    }
    int digits=FindDigits(max);
    int pass;
    for(pass=1;pass<=digits;pass++)
    {
        for(i=0;i<n;i++)
        {
            InsertBin(bin,a[i],pass);
        }
        i=0; /*for bin*/
        int j=0; /*for original array*/
        while(i<10)
        {
            if(bin[i]==NULL)
            {
                i++;
            }
            else
            {
                int x=DeleteBin(bin,i);
                a[j]=x;
                j++;
            }
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
    RadixSort(a,n);
    printf("the sorted array will be: \n");
    Display(a,n);
}
