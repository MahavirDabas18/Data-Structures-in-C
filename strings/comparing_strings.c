#include <stdio.h>
#include <stdlib.h>

int main()
{char a[30],b[30];
int i,j;
printf("enter string a: \n");
gets(a);
printf("enter string b: \n");
gets(b);
for(i=0,j=0;a[i]!='\0' && b[j]!='\0' /*to take care of case of being equal*/;i++,j++)
{
    if(a[i]!=b[j])
    {
        break;
    }
}
if(a[i]==b[j])
{
    printf("both strings are same");
}
else if(a[i]>b[j])
{
    printf("string b comes first");
}
else
{
    printf("string a comes first");
}
}

