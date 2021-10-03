#include <stdio.h>
#include <stdlib.h>

int main()
{char s[20];
int i,vcount=0,ccount=0;
printf("enter string: \n");
gets(s);
for(i=0;s[i]!='\0';i++)
{
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
       s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
    {
        vcount++;
    }
    else
    {
        if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122))
        {
            ccount++;
        }
    }

}
printf("consonants: %d    vowels: %d  \n",ccount,vcount);
}

