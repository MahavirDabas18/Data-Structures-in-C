#include <stdio.h>
#include <stdlib.h>

int main()
{char a[30];
int i,j;
printf("enter string: \n");
gets(a);
for(j=0;a[j]!='\0';j++)
{

}
j--; /*j is now pointing to last char in string*/
for(i=0;i<j;i++,j--)
{
    if(a[i]!=a[j]) /*condition for not palindrome*/
    {   printf("entered string is not palindrome \n");
        break;
    }
}
if(i==j) /*if i reaches j then it is palindrome*/
{
    printf("entered string is palindrome \n");
}
}

