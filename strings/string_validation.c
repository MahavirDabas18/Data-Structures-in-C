#include <stdio.h>
#include <stdlib.h>

int main()
{char *s="mahav@ir"; /*validating a string, no special characters*/
int valid(char *);
printf("%d",valid(s));
}
int valid(char *s)
{int i;
    for(i=0;s[i]!='\0';i++)
{
    if(!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122) && !(s[i]>=48 && s[i]<=57))
    {
        return 0; /*not valid*/
    }

}
return 1;  /*valid*/
}

