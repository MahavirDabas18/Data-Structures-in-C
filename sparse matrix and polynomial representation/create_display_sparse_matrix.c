#include <stdio.h>
#include <stdlib.h>
struct element /*non zero elements of a sparse matrix*/
{
    int r; /*row number*/
    int c; /*column number*/
    int x; /*element*/
};
struct sparse /*sparse matrix-3 column representation*/
{
    int m; /*no of rows in sparse matrix*/
    int n; /*no of columns in sparse matrix*/
    int num; /*no of non zero elements in sparse matrix*/
    struct element *e; /*a pointer to contain all the non zero elements which are defined by this data type*/

};
int main()
{struct sparse s;
void create(struct sparse*);
void display(struct sparse);
create(&s);
display(s);
}
void create(struct sparse *s)
{   int i;
    printf("enter rows of sparse matrix: \n");
    scanf("%d",&s->m);
    printf("enter columns of sparse matrix: \n");
    scanf("%d",&s->n);
    printf("enter number of non zero elements in the sparse matrix: \n");
    scanf("%d",&s->num);
    s->e=(struct element*)malloc(s->num*sizeof(struct element));
    for(i=0;i<s->num;i++)
    {
        printf("enter row number,column number and value of non zero element number %d: \n",i+1); /*elements are stored row wise*/
        scanf("%d %d %d",&s->e[i].r,&s->e[i].c,&s->e[i].x);
    }

}
void display(struct sparse s)
{
    int i,j,k;
    printf("your sparse matrix is: \n");
    k=0; /*pointing to array of elements which are stored first row and then column wise*/
    for(i=1;i<=s.m;i++) /*we start i and j from 1 as values of row and columns have been stored while defining structure element*/
        /*loops runs first row wise then column wise*/
    {
        for(j=1;j<=s.n;j++)
        {
            if(i==s.e[k].r && j==s.e[k].c) /*row and column match to the kth element in the array of non zero elements*/
            {
                printf("%d \t",s.e[k].x);
                k++; /*increment k to the next non zero element as we are done with this element*/
            }
            else
            {
                printf("0 \t");
            }
        }
        printf("\n");
    }
}
