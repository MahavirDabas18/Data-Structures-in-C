#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array p={{2,3,4,5,6},5,10};
int sum(struct array,int);
int main()
{ printf("%d ",sum(p,p.length));
}
int sum(struct array p,int length)
{
    if(length==1)
    {
        return p.a[0];
    }
    else
    {
        return p.a[length-1]+sum(p,length-1);
    }
}



