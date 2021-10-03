#include <stdio.h>
#include <stdlib.h>
int main()
{int *p;
int i;
int *q;
int n;
p=(int*)malloc(5*sizeof(int));
for(i=0;i<5;i++)
{
    printf("enter value: \n");
    scanf("%d",&p[i]);
}
printf("enter increased size: \n");
scanf("%d",&n);
q=(int*)malloc(n*sizeof(int));
for(i=0;i<5;i++)
{
    q[i]=p[i];
}
free(p);
p=q;
q=NULL;
for(i=0;i<10;i++)
{
    printf("%d \n",p[i]);
}
}

