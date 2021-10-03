#include <stdio.h>
#include <stdlib.h>

int main()
{void toh(int,char,char,char);
int n;
printf("enter no of discs: \n");
scanf("%d",&n);
toh(n,'A','C','B');
}
void toh(int n,char source,char destination,char helper)
{
    if(n==1) /*base case only 1 disc so move from a to c in one move,the exact step is mentioned as no recursion in used in base case*/
    {
        printf("move disc %d from %c to %c \n",n,source,destination);
    }
    else
    {
        /*step 1 is to get top n-1 discs to b using toh function*/
        toh(n-1,source,helper,destination);
        /*STEP 2-TO GET LAST NTH DISC FROM A TO C IN ONE MANUAL MOVE*/
        printf("move disc %d from %c to %c \n",n,source,destination);
        /*step 3 is to get n-1 discs on B TO C USING TOH FORMAT*/
        toh(n-1,helper,destination,source);
    }
}
