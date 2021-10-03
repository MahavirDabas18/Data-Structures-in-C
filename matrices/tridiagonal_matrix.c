#include <stdio.h>
#include <stdlib.h>
struct tridiag
{
    int *a;
    int size;
};
int main()
{struct tridiag t;
int i,j,x;
void set(struct tridiag *,int,int,int);
int get(struct tridiag,int,int);
void display(struct tridiag);
printf("enter the dimension of the tridiagonal matrix: \n");
scanf("%d",&t.size);
t.a=(int*)malloc((3*t.size-2)*sizeof(int));
for(i=1;i<=t.size;i++)
{
    for(j=1;j<=t.size;j++)
    {
        if(i-j==1||i-j==0||i-j==-1) /*lower diagonal,main diagonal,upper diagonal respectively*/
        {
            printf("enter element (%d,%d): \n",i,j);
            scanf("%d",&x);
            set(&t,i,j,x);

        }
    }
}
printf("the element at (%d,%d) is: %d \n",2,4,get(t,2,4)); /*we don't set this element but we'll still get it*/
display(t);
}
void set(struct tridiag* t,int i,int j,int x)
{int index;
    if(i-j==1)
    {
        index=j-1;
        t->a[index]=x;
    }
    else if(i-j==0)
    {
        index=(t->size-1)+(j-1);
        t->a[index]=x;
    }
    else if(i-j==-1)
    {
        index=(2*t->size-1)+(j-2);
        t->a[index]=x;
    }
    else
    {
        printf("the coordinates do not lie in the required diagonals \n");
    }
}
int get(struct tridiag t,int i,int j)
{int index;
if(i-j==1)
    {
        index=j-1;
        return t.a[index];
    }
    else if(i-j==0)
    {
        index=(t.size-1)+(j-1);
        return t.a[index];
    }
    else if(i-j==-1)
    {
        index=(2*t.size-1)+(j-2);
        return t.a[index];
    }
    else
    {
        return 0;
    }

}
void display(struct tridiag t)
{
    int i,j;
    printf("the tridiagonal matrix is: \n");
    for(i=1;i<=t.size;i++)
    {
        for(j=1;j<=t.size;j++)
        {
            printf("%d \t",get(t,i,j));
        }
        printf("\n");
    }
}
