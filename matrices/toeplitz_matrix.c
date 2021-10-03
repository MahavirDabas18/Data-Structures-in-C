#include <stdio.h>
#include <stdlib.h>
struct toeplitz
{
    int *a;
    int size;
};
int main()
{struct toeplitz t;
int i,j,x;
void set(struct toeplitz*,int,int,int);
int get(struct toeplitz,int,int);
void display(struct toeplitz);
printf("enter dimension of toeplitz matrix: \n");
scanf("%d",&t.size);
t.a=(int*)malloc(2*t.size-1);
for(i=1;i<=t.size;i++)
{
    for(j=1;j<=t.size;j++)
    {
        if(i==1)
        {
            printf("enter element (%d,%d): \n",i,j);
            scanf("%d",&x);
            set(&t,i,j,x);
        }
        else
        {
            if(j==1)
            {
                printf("enter element (%d,%d): \n",i,j);
                scanf("%d",&x);
                set(&t,i,j,x);
            }
        }

    }
}
printf("element at (%d,%d) is: %d \n",4,2,get(t,4,2)); /*i have not set this element but will still get it*/
display(t);
}
void set(struct toeplitz *t,int i,int j,int x)
{int index;
for(i=1;i<=t->size;i++)
{
    for(j=1;j<=t->size;j++)
    {
        if(i==1) /*upper triangular matrix defined by 1st row elements*/
        {
            index=(j-i);
            t->a[index]=x;
        }
        else /*lower triangular matrix defined by 1st column elements*/
        {
            if(j==1)
            {
                index=(t->size)+(i-j-1);
                t->a[index]=x;
            }
        }

    }
}
}
int get(struct toeplitz t,int i,int j)
{int index;
    if(i>j) /*upper triangular matrix defined by row elements*/
    {
        index=(j-i);
        return t.a[index];
    }
    else /*lower triangular matrix defined by column elements*/
    {
        index=(t.size)+(i-j-1);
        return t.a[index];
    }
}
void display(struct toeplitz t)
{
    int i,j;
    printf("your toeplitz matrix is: \n");
    for(i=1;i<=t.size;i++)
    {
        for(j=1;j<=t.size;j++)
        {
            printf("%d \t",get(t,i,j));
        }
        printf("\n");
    }
}
