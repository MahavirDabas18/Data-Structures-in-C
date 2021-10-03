#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct term
{
    int coeff;
    int exp;
};
struct poly
{
    int size; /*number of non zero terms*/
    struct term* t;
};
int main()
{struct poly p;
int x;
void create(struct poly*);
void display(struct poly);
int evaluate(struct poly,int);
create(&p);
display(p);
printf("enter value of x: \n");
scanf("%d",&x);
printf("value of polynomial at x=%d is: %d \n",x,evaluate(p,x));
}
void create(struct poly *p)
{
    printf("enter number of non zero terms in the polynomial: \n");
    scanf("%d",&p->size);
    p->t=(struct term*)malloc(p->size*sizeof(struct term)); /*dynamically created array*/
    int i;
    printf("****caution-enter non zero terms in decreasing order of power i.e highest power to lowest**** \n");
    for(i=0;i<p->size;i++)
    {
        printf("enter exponent and coefficient of non zero term number %d: \n",i+1); /*we enter terms starting from highest powers*/
        scanf("%d%d",&p->t[i].exp,&p->t[i].coeff);
    }

}
void display(struct poly p)
{
    int i;
    for(i=0;i<(p.size-1);i++)
    {
        printf("%d.x^%d+ \t",p.t[i].coeff,p.t[i].exp); /*all terms except the last term*/
    }
    /*i value incremented to i=p.size-1*/
    printf("%d.x^%d \n",p.t[i].coeff,p.t[i].exp); /*last term printed with no plus sign*/
}
int evaluate(struct poly p,int x)
{
    int i,sum=0;
    for(i=0;i<p.size;i++)
    {
        sum+=(p.t[i].coeff)*pow(x,p.t[i].exp);
    }
    return sum;
}




