#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array p={{2,3,4,5,6},5,10};
void reverse(struct array*);
void swap(int *,int *);
int main()
{reverse(&p);
int i;
for(i=0;i<p.length;i++)
{
    printf("%d ",p.a[i]);
}
}
void swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
void reverse(struct array *p)
{
  int i,j;
  for(i=0,j=p->length-1;i<j;i++,j--)
  {
      swap(&p->a[i],&p->a[j]);
  }
}






