#include <stdio.h>
#include <stdlib.h>

int main()
{char a[]="medical";
char b[]="decimal";
int i, h[26]={0};
for(i=0;a[i]!='\0';i++)
{
    h[a[i]-97]++;
}
for(i=0;b[i]!='\0';i++)
{
    h[b[i]-97]--;
}
for(i=0;i<26;i++)
{
    if(h[i]!=0)
    {
        printf("not anagram \n");
        break;
    }
}

if(i==26)
{
    printf("anagram \n");
}

}
