#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array p={{2,3,4,5,6},5,10};
void set(struct array*,int,int);
int main()
{set(&p,2,101);
int i;
for(i=0;i<p.length;i++)
{
    printf("%d ",p.a[i]);
}
}
void set(struct array *p,int index,int x)
{
    if(index>=0 && index<p->length)
    {
        p->a[index]=x;
    }
}




