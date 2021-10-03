#include <stdio.h>
#include <stdlib.h>

int main()
{int a[8]={2,3,4,6,7,10,11,12};
int i,j,diff;
printf("the missing elements are: \n");
diff=a[0];
for(i=0;i<8;i++)
{
    if(a[i]-i!=diff)
    {
        for(j=diff;j<a[i]-i;j++)
        {
            printf("%d \n",i+diff);
            diff++;
        }
    }
}
}
