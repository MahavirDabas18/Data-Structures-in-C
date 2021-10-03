#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array p={{1,2,3,4,7,8,9},7,10};
void insert_sort(struct array *,int);
int main()
{insert_sort(&p,5);
int i;
for(i=0;i<p.length;i++)
{
    printf("%d ",p.a[i]);
}
}
void insert_sort(struct array *p,int x)
{int i;
    if(p->length<p->size)
    {
        for(i=(p->length)-1;p->a[i]>x;i--)
        {
            p->a[i+1]=p->a[i];
        }
        p->a[i+1]=x;
        p->length++;
    }
}
