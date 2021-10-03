#include <stdio.h>
#include <stdlib.h>
struct element
{
    int r;
    int c;
    int x;
} ;
struct sparse
{
    int m;
    int n;
    int num;
    struct element* e;

};
int main()
{
    void create(struct sparse*);
    void display(struct sparse);
    struct sparse* add(struct sparse,struct sparse);
    struct sparse s1,s2,*s3;
    create(&s1);
    create(&s2);
    s3=add(s1,s2);
    printf("sparse matrix 1: \n");
    display(s1);
    printf("sparse matrix 2: \n");
    display(s2);
    printf("sum of the 2 matrices: \n");
    display(*s3);

}
void create(struct sparse* s)
{
    printf("enter number of rows and columns of sparse matrix: \n");
    scanf("%d%d",&s->m,&s->n);
    printf("enter number of non zero elements of the sparse matrix: \n");
    scanf("%d",&s->num);
    s->e=(struct element*)malloc(s->num*sizeof(struct element));
    int i;
    for(i=0;i<s->num;i++)
    {
        printf("enter row number,column number and the value of non zero element number %d: \n",i+1);
        scanf("%d%d%d",&s->e[i].r,&s->e[i].c,&s->e[i].x);
    }
}
struct sparse* add(struct sparse s1,struct sparse s2)
{
    struct sparse* sum;
    if(s1.m!=s2.m && s1.n!=s2.n)
    {
        return 0;
    }
    /*else condition*/
    sum=(struct sparse*)malloc(sizeof(struct sparse)); /*now sum is pointing to a structure sparse*/
    sum->e=(struct element*)malloc((s1.num+s2.num)*sizeof(struct element)); /*now e for sum has been created which can have max value s1.num+s2.num*/

    int i=0,j=0,k=0; /*pointing to s1.e,s2.e and sum->e respectively*/
    while(i<s1.num && j<s2.num) /*loops breaks if even one of them exceeds the value*/
    {
        if(s1.e[i].r<s2.e[j].r) /*row comparison*/
        {
            sum->e[k]=s1.e[i];
            k++,i++;
        }
        else if(s1.e[i].r>s2.e[j].r)
        {
            sum->e[k]=s2.e[j];
            k++,j++;
        }
        else
        {
            if(s1.e[i].c<s2.e[j].c) /*column representation*/
            {
                sum->e[k]=s1.e[i];
                k++,i++;
            }
            else if(s1.e[i].c<s2.e[j].c)
            {
                sum->e[k]=s2.e[j];
                k++,j++;
            }
            else /*case of addition*/
            {
                sum->e[k]=s1.e[i];
                sum->e[k].x+=s2.e[j].x;
                i++,j++,k++;
            }
            for(;i<s1.num;i++) /*rest of the elements of either one*/
            {
                sum->e[k]=s1.e[i];
                i++,k++;
            }
            for(;j<s2.num;j++)
            {
                sum->e[k]=s2.e[j];
                k++,j++;
            }
            sum->m=s1.m;
            sum->n=s1.n;
            sum->num=k;
            return sum;
        }
    }
}
void display(struct sparse s)
{
    int i,j,k=0; /* i and j take care of rows and k take cares of non zero elements*/
    for(i=1;i<=s.m;i++)
    {
        for(j=1;j<=s.n;j++)
        {
            if(i==s.e[k].r && j==s.e[k].c) /*case of non zero element*/
            {
                printf("%d \t",s.e[k].x);
                k++;
            }
            else
            {
                printf("0 \t");
            }
        }
        printf(" \n");
    }


}


