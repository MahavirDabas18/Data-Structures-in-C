#include <stdio.h>
#include <stdlib.h>
struct lower
{
    int *a;
    int size;
};
struct lower l;
int main()
{int i,j,k;
void set(struct lower *,int,int,int);
int get(struct lower,int,int);
void display(struct lower);
printf("enter dimension of lower triangular matrix: \n");
scanf("%d",&l.size);
l.a=(int*)malloc(((l.size)*(l.size+1)/2)*sizeof(int));
for(i=1;i<=l.size;i++)
{
    for(j=1;j<=l.size;j++)
    {
        if(i>=j)
        {
            printf("enter element (%d,%d): \n",i,j);
            scanf("%d",&k);
            set(&l,i,j,k);
        }
    }
}
printf("%d \n",get(l,4,5));
display(l);
}
void set(struct lower *l,int i,int j,int x)
{int index;
    if(i>=j)
    {
        index=(i*(i-1)/2)+(j-1);
        l->a[index]=x;
    }
}
int get(struct lower l,int i,int j)
{int index;
    if(i>=j)
    {
         index=(i*(i-1)/2)+(j-1);
         return l.a[index];
    }
    else
    {
        return 0;
    }
}
void display(struct lower l)
{
    int i,j,index;
    printf("your lower triangular matrix is: \n");
    for(i=1;i<=l.size;i++)
    {
        for(j=1;j<=l.size;j++)
        {
            if(i>=j)
            {
                index=(i*(i-1)/2)+(j-1);
                printf("%d \t",l.a[index]);
            }
            else
            {
                printf("0 \t");
            }
        }
        printf("\n");
    }
}

