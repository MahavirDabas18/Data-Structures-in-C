#include <stdio.h>
#include <stdlib.h>

int main()
{char a[30];
int i,j,count;
printf("enter string: \n");
gets(a);
for(i=0;a[i]!='\0';i++)
{
    if(a[i]!=-1 /*duplicates are not considered again*/ && a[i]!=' ' /*space character is not considered*/)
    {   count=0;
        for(j=i+1;a[j]!='\0';j++)
        { if(a[i]==a[j])
        {
            count++;
            a[j]=-1;
        }

        }
        if(count>0)
        {
            printf("char: %c   occurrences: %d \n",a[i],count+1);
        }
    }
}

}


