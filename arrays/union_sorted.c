#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array m={{3,4,5,6,10},5,10};
struct array n={{2,4,5,7,12},5,10};
struct array o={{},0,10};
void union1(struct array*,struct array*,struct array*);
int main()
{union1(&m,&n,&o);
int i;
for(i=0;i<o.length;i++)
{
    printf("%d ",o.a[i]);
}
}
void union1(struct array *m,struct array *n,struct array *o)
{int i=0,j=0,k=0;
while(i<m->length && j<n->length)
{
    if(m->a[i]<n->a[j])
    {
        o->a[k]=m->a[i];
        i++;
        k++;
        o->length++;
    }
    else if(m->a[i]>n->a[j])
    {
        o->a[k]=n->a[j];
        k++;
        j++;
        o->length++;
    }
    else /*condition of equality*/
    {
        o->a[k]=m->a[i];
        i++;
        j++;
        k++;
        o->length++;
    }

}
for(;i<m->length;i++)
    {
        o->a[k]=m->a[i];
        k++;
        i++;
        o->length++;
    }
    for(;j<n->length;j++)
    {
        o->a[k]=n->a[j];
        j++;
        k++;
        o->length++;
    }

}
