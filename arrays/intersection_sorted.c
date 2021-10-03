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
void intersection(struct array*,struct array*,struct array*);
int main()
{intersection(&m,&n,&o);
int i;
for(i=0;i<o.length;i++)
{
    printf("%d ",o.a[i]);
}
}
void intersection(struct array *m,struct array *n,struct array *o)
{int i=0,j=0,k=0;
while(i<m->length && j<n->length)
{
    if(m->a[i]<n->a[j])
    {
        i++;

    }
    else if(m->a[i]>n->a[j])
    {
        j++;

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
}
