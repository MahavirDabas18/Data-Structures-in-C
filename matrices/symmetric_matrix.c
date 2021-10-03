#include <stdio.h>
#include <stdlib.h>
struct symmetric
{
    int *a;
    int size;
};
int main()
{int i,j,x;
void set(struct symmetric*,int,int,int);
int get(struct symmetric,int,int);
void display(struct symmetric);
struct symmetric s;
printf("enter dimension of symmetric matrix: \n");
scanf("%d",&s.size);
s.a=(int*)malloc((s.size*(s.size+1)/2)*sizeof(int));
for(i=1;i<=s.size;i++)
{
    for(j=1;j<=s.size;j++)
    {
        if(i>=j) /*we are setting the lower triangular part only*/
        {   printf("enter element (%d,%d): \n",i,j);
            scanf("%d",&x);
            set(&s,i,j,x);
        }
    }
}
printf("the element at (1,3) is: %d \n",get(s,1,3)); /*we have not set i<j elements but we'll still get them*/
display(s);
}
void set(struct symmetric*s,int i,int j,int x)
{int index;
    if(i>=j) /*set takes only lower triangular part to store in 1d array*/
    {   index=(i*(i-1)/2)+(j-1);
        s->a[index]=x;
    }
}
int get(struct symmetric s,int i,int j)
{
    int index;
    if(i>=j)
    {
        index=(i*(i-1)/2)+(j-1);
        return s.a[index];
    }
    else
    {
        index=(j*(j-1)/2)+(i-1); /*for i>j just replace i and j in index formula to get index of 1d array for upper triangular matrix*/
        return s.a[index];
    }
}
void display(struct symmetric s)
{
    int i,j;
    printf("your symmetric matrix is: \n");
    for(i=1;i<=s.size;i++)
    {
        for(j=1;j<=s.size;j++)
        {
            printf("%d \t",get(s,i,j));
        }
        printf("\n");
    }
}
