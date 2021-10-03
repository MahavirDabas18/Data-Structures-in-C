#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *a;
    int size;
    int length;
};
struct array p;
void display(struct array);

int main()
{int i;
printf("enter the size of the array: \n");
scanf("%d",&p.size);
p.a=(int*)malloc((p.size*sizeof(int)));
printf("enter length of the array: \n");
scanf("%d",&p.length);
for(i=0;i<p.length;i++)
{
    printf("enter element: \n");
    scanf("%d",&p.a[i]);
}
display(p);

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
