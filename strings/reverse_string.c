#include <stdio.h>
#include <stdlib.h>

int main()
{char  s[30],temp;
int i,j;
printf("enter your string: \n");
gets(s);
for(j=0;s[j]!='\0';j++)
{

}
j--; /*now j is a pointer to last char of string*/
for(i=0;i<j;i++,j--)
{temp=s[i];
s[i]=s[j];
s[j]=temp;
}
printf("the reversed string is: \n");
puts(s);
}

