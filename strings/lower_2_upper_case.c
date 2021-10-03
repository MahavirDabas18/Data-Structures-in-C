#include <stdio.h>
#include <stdlib.h>

int main()
{char s[20];
int i;
printf("enter string in lower case: \n");
gets(s);
for(i=0;s[i]!='\0';i++)
{   if(s[i]>=97 && s[i]<=122)
{
    s[i]-=32;
}

}
printf("the string in upper case is: \n");
puts(s);

}

