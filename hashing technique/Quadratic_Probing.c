#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*hash function is h(x)=x%10*/
int hash(int key)
{
    return key%10;
}
int QuadraticProbing(int* HT[],int key)
{
    int index=hash(key);
    int i=0;
    int x=(index+(i*i))%10; /*quadratic probing*/
    while(!(HT[x]==0))
    {
        i++;
        x=(index+(i*i))%10;
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
        index=QuadraticProbing(HT,key);
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
        int x=(index+(i*i))%10; /*quadratic probing*/
        while(!(HT[x]==key || HT[x]==0))
        {
            i++;
            x=(index+(i*i))%10;
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
    Insert(HT,23);
    Insert(HT,43);
    Insert(HT,13);
    Insert(HT,27);
    Search(HT,13)!=-1?printf("13 is present at index %d \n",Search(HT,13)):printf("13 is not present in the hashtable \n");
    Search(HT,27)!=-1?printf("27 is present at index %d \n",Search(HT,27)):printf("27 is not present in the hashtable \n");
}
