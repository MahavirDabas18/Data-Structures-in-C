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
void delete(struct array*,int);

int main()
{delete(&p,3);
display(p);

}
void delete(struct array *p,int index)
{
    int i;
    for(i=index+1;i<p->length;i++)
    {
        p->a[i-1]=p->a[i];
    }
    p->length--;
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
