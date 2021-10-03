#include <stdio.h>
#include <stdlib.h>
struct diag
{
    int a[10];
    int size;
};
int main()
{struct diag d;
void set(struct diag* ,int,int,int);
int get(struct diag,int,int);
void display(struct diag);
d.size=5;
set(&d,0,0,3);
set(&d,1,1,7);
set(&d,2,2,4);
set(&d,3,3,9);
set(&d,4,4,6);
printf("%d \n",get(d,2,1));
display(d);
}
void set(struct diag *d,int i,int j,int x)
{
    if(i==j && i<d->size && j<d->size) /*only diagonal elements are to be set*/
    {
        d->a[i]=x;
    }

}
int get(struct diag d,int i,int j)
{
    if(i==j && i<d.size && j<d.size)
    {
        return d.a[i];
    }
    else
    {
        return 0;
    }
}
void display(struct diag d)
{int i,j;
    for(i=0;i<d.size;i++)
    {
        for(j=0;j<d.size;j++)
        {
            if(i==j)
            {
                printf("%d \t",d.a[i]);
            }
            else
            {
                printf("0 \t");
            }
        }
        printf(" \n");
    }
}


