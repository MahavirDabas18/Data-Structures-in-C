#include <stdio.h>
#include <stdlib.h>

int main()
{char s[100];
int i,words=1;
printf("enter string: \n");
gets(s);
for(i=0;s[i]!='\0';i++)
{
    if(s[i]==' ' && s[i-1]!=' ')  /*accounting for white spaces as well*/
    {
        words++;
    }
}
printf("no of words: %d \n",words);
}

