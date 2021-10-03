#include <stdio.h>
#include <stdlib.h>

int main()
{int a[10]={3,7,4,9,12,6,1,11,2,10};
int h,l,i;
h=l=a[0];
int *hasht;
for(i=0;i<10;i++) /*finding lowesr and highest value in hashtable */
{
    if(a[i]>h)
    {
        h=a[i];
    }

}
for(i=0;i<10;i++)
{
    if(a[i]<l)
    {
        l=a[i];
    }
}
hasht=(int*)malloc((h+1)*sizeof(int)); /*creating hashtable*/
for(i=0;i<=h;i++) /*setting each value of hashtable zero */
{
    hasht[i]=0;
}
for(i=0;i<10;i++) /*incrementing indexes in hashtable in accordance to elements in array */
{
    hasht[a[i]]++;
}
printf("the missing elements are: \n");
for(i=l;i<=h;i++) /*printing missing elements which are all zero */
{
    if(hasht[i]==0)
    {
        printf("%d \n",i);
    }
}




}
