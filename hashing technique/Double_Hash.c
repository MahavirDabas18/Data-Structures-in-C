#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*hash function is h(x)=x%10*/
/*helper function is h'(x)=7-(x%7)*/
int hash(int key)
{
    return key%10;
}
int DoubleHash(int* HT[],int key)
{
    int index=hash(key);
    int i=0;
    int x=(index+i*(7-(key%7)))%10; /*double hash*/
    while(!(HT[x]==0))
    {
        i++;
        x=(index+i*(7-(key%7)))%10;
    }
    return x;
}
void Insert(int* HT[],int key)
{
    int index=hash(key);
    if(HT[index]==0) /*first key to be inserted*/
    {
        HT[index]=key;
    }
    else
    {
        index=DoubleHash(HT,key);
        HT[index]=key;
    }
}
int Search(int* HT[],int key)
{
    int index=hash(key);
    if(HT[index]==0)
    {
        return -1; /*we return -1 when the search is unsuccessful*/
    }
    else
    {
        int i=0;
        int x=(index+i*(7-(key%7)))%10; /*double hash*/
        while(!(HT[x]==key || HT[x]==0))
        {
            i++;
            x=(index+i*(7-(key%7)))%10;
        }
        /*now either x is at empty space or it is at the key's index*/
        if(HT[x]==0)
        {
            return -1;
        }
        return x;
    }
}
int main()
{
    int* HT=(int*)malloc(10*sizeof(int));
    int i;
    for(i=0;i<10;i++)
    {
        HT[i]=0;
    }
    Insert(HT,5);
    Insert(HT,15);
    Insert(HT,25);
    Insert(HT,35);
    Search(HT,15)!=-1?printf("15 is present at index %d \n",Search(HT,15)):printf("15 is not present in the hashtable \n");
    Search(HT,35)!=-1?printf("35 is present at index %d \n",Search(HT,35)):printf("35 is not present in the hashtable \n");
}
