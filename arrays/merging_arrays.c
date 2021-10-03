#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array m={{3,8,16,20,25},5,10};
struct array n={{4,10,12,22,23},5,10};
struct array o={{0,0,0,0,0,0,0,0,0,0},10,10};
void merge(struct array*,struct array*,struct array*);
int main()
{merge(&m,&n,&o);
int i;
for(i=0;i<o.length;i++)
{
    printf("%d ",o.a[i]);
}
}
void merge(struct array *m,struct array *n,struct array *o)
{
    int i=0,j=0,k=0;
    while(i<m->length && j<n->length)
    {
        if(m->a[i]<n->a[j])
        {
            o->a[k]=m->a[i];
            i++;
            k++;
        }
        else
        {
            o->a[k]=n->a[j];
            j++;
            k++;
        }
    }
    for(;i<m->length;i++)
    {
        o->a[k]=m->a[i];
        i++;
        k++;
    }
    for(;j<n->length;j++)
    {
        o->a[k]=n->a[j];
        j++;
        k++;
    }

}
