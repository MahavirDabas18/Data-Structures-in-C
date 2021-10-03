#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*hash function is h(x)=x%10*/
int hash(int key)
{
    return key%10;
}
int LinearProbe(int* HT[],int key) /*this function gives the next free space in the hashtable to store an element*/
{
    int index=hash(key);
    int i=0;
    int x=(index+i)%10; /*linear probing formula*/
    while(!(HT[x]==0))
    {
        i++;
        x=(index+i)%10;
    }
    /*now x is pointing at the free space*/
    return x;
}
void Insert(int* HT[],int key)
{
    int index=hash(key);
    if(HT[index]==0) /*nothing at this key*/
    {
        HT[index]=key;
    }
    else
    {
        index=LinearProbe(HT,key);
        HT[index]=key;
    }
}
int Search(int* HT[],int key)
{
    int index=hash(key);
    if(HT[index]==0) /*the index is empty-no element is present*/
    {
        return -1; /*we return -1 if not found*/
    }
    else /*the index has something*/
    {
        int i=0;
        int x=(index+i)%10; /*linear probing formula*/
        while(!(HT[x]==key || HT[x]==0))
        {
            i++;
            x=(index+i)%10;
        }
        if(HT[x]==0)
        {
            return -1; /*element not found*/
        }
        return x; /*when the element is found we return the index*/

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
    Insert(HT,22);
    Insert(HT,32);
    Insert(HT,43);
    Insert(HT,54);
    Insert(HT,99);
    Search(HT,32)!=-1?printf("32 is present at index %d \n",Search(HT,32)):printf("32 is not present in the hashtable \n");
    Search(HT,78)!=-1?printf("32 is present at index %d \n",Search(HT,78)):printf("78 is not present in the hashtable \n");
}
