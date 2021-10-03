#include <stdio.h>
#include <stdlib.h>
struct upper
{
    int *a;
    int size;
};
int main()
{struct upper u;
int i,j,x;
void set(struct upper*,int,int,int);
int get(struct upper,int,int);
void display(struct upper);
printf("enter dimension of upper triangular matrix: \n");
scanf("%d",&u.size);
u.a=(int*)malloc((u.size*(u.size+1)/2)*sizeof(int));
for(i=1;i<=u.size;i++)
{
    for(j=1;j<=u.size;j++)
    {
        if(j>=i)
        {
            printf("enter element (%d,%d): \n",i,j);
            scanf("%d",&x);
            set(&u,i,j,x);
        }
    }
}
printf("%d \n",get(u,5,4));
display(u);
}
void set(struct upper *u,int i,int j,int x)
{
    int index;
    if(j>=i)
    {
        index=(j*(j-1)/2)+(i-1);
        u->a[index]=x;
    }
}
int get(struct upper u,int i,int j)
{int index;
    if(j>=i)
    {
        index=(j*(j-1)/2)+(i-1);
        return u.a[index];
    }
    else
    {
        return 0;
    }
}
void display(struct upper u)
{
    int i,j,index;
    printf("your upper triangular matrix is: \n");
    for(i=1;i<=u.size;i++)
    {
        for(j=1;j<=u.size;j++)
        {
            if(j>=i)
            {
                index=(j*(j-1)/2)+(i-1);
                printf("%d \t",u.a[index]);
            }
            else
            {
                printf("0 \t");
            }
        }
        printf("\n");
    }
}

