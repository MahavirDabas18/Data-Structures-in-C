#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array p={{1,2,3,-4,-2,-9,-5},7,10};
void fun(struct array *);
void swap(int*,int*);
int main()
{fun(&p);
int i;
for(i=0;i<p.length;i++)
{
    printf("%d ",p.a[i]);
}
}
void swap(int* x,int* y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
void fun(struct array *p)
{int i=0,j=(p->length-1);
while(i<j)
{
    while(p->a[i]<0)
{
    i++;
}
while(p->a[j]>0)
{
    j--;
}
swap(&p->a[i],&p->a[j]);
}
}
