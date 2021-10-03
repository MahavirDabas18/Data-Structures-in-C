#include <stdio.h>
#include <stdlib.h>
struct array
{
    int a[10];
    int size;
    int length;
};
struct array p={{1,2,3,4,5,6},10,6};
void display(struct array);
void append(struct array *,int);
void insert(struct array *,int,int);

int main()
{append(&p,5);
insert(&p,2,8);
display(p);

}
void append(struct array *m,int x)
{
    if(m->length<m->size)
    {
        m->a[m->length]=x;
        m->length++;

    }
}
void insert(struct array *m,int index,int x)
{int i;
    if(m->size>m->length && index>=0 && index<m->length /*because then it will be case of append*/)
    {
       for(i=m->length;i>index;i--)
       {
           m->a[i]=m->a[i-1];
       }
       m->a[index]=x;
       m->length++;
    }
}
void display(struct array p)
{
    int i;
    printf("the elements are: \n");
    for(i=0;i<p.length;i++)
    {
        printf("%d \n",p.a[i]);
    }
}
