#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array p={{6,3,8,5,9},5,10};
void lshift(struct array *);
int main()
{lshift(&p);
int i;
for(i=0;i<p.length;i++)
{
    printf("%d ",p.a[i]);
}
}
void lshift(struct array *p)
{
    int i;
    for(i=1;i<p->length;i++)
    {
        p->a[i-1]=p->a[i];
    }
    p->a[p->length-1]=0;
}
