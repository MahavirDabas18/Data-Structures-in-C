#include <stdio.h>
#include <stdlib.h>

int main()
{char s[20];
int i;
printf("enter the string: \n");
gets(s);
for(i=0;s[i]!='\0';i++)
{
    if(s[i]>=97 && s[i]<=122) /*lower case*/
    {
        s[i]-=32;
    }
    else
    {
        if(s[i]>=65 && s[i]<=90) /*upper case*/
        {
            s[i]+=32;
        }
    }
}
printf("the string with toggled case will be: \n");
puts(s);

}

