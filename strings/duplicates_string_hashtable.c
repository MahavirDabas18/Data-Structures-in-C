#include <stdio.h>
#include <stdlib.h>

int main()
{char a[30];
printf("enter string: \n");
gets(a);
int h[26]={0};
int i;
for(i=0;a[i]!='\0';i++)
{
    h[a[i]-97]++;
}
for(i=0;i<26;i++)
{
    if(h[i]>1)
    {
        printf("char: %c  occurrences: %d \n",i+97,h[i]);
    }
}
}


