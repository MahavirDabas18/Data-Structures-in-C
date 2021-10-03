#include <stdio.h>
#include <stdlib.h>
struct array
{int a[10];
int length;
int size;
};
struct array p={{1,2,3,4,7,8,9},7,10};
int sorted(struct array);
int main()
{printf("%d ",sorted(p));
}
int sorted(struct array p)
{
    int i=0;
    for(;i<p.length-2;i++)
    {
        if(p.a[i]<p.a[i+1])
        {

        }
        else
        {
            return 0;
        }
    }
    return 1;
}
