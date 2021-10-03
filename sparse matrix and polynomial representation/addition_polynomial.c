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
{struct poly p1,p2,*p3;
int x;
void create(struct poly*);
void display(struct poly);
struct poly* add(struct poly,struct poly);
int evaluate(struct poly,int);
printf("***POLYNOMIAL ONE*** \n");
create(&p1);
printf("***POLYNOMIAL TWO*** \n");
create(&p2);
p3=add(p1,p2);
printf("***POLYNOMIAL ONE*** \n");
display(p1);
printf("***POLYNOMIAL TWO*** \n");
display(p2);
printf("***THEIR SUM IS THE RESULTING POLYNOMIAL*** \n");
display(*p3);
printf("enter value of x to evaluate the addition: \n");
scanf("%d",&x);
printf("value of sum of polynomials at x=%d is: %d \n",x,evaluate(*p3,x));
}
void create(struct poly *p)
{
    printf("enter number of non zero terms in the polynomial: \n");
    scanf("%d",&p->size);
    p->t=(struct term*)malloc(p->size*sizeof(struct term)); /*dynamically created array*/
    int i;
    printf("****caution-enter non zero terms in decreasing order of power i.e highest power to lowest power**** \n");
    for(i=0;i<p->size;i++)
    {
        printf("enter exponent and coefficient of non zero term number %d: \n",i+1); /*we enter terms starting from highest powers*/
        scanf("%d%d",&p->t[i].exp,&p->t[i].coeff);
    }

}
struct poly* add(struct poly p1,struct poly p2)
{
  struct poly* sum;
  sum=(struct poly*)malloc(sizeof(struct poly)); /*dynamically created structure to which sum is pointing to is created*/
  sum->t=(struct term*)malloc((p1.size+p2.size)*sizeof(struct term)); /*array of terms created for structure to which sum is pointing to*/
  int i=0,j=0,k=0; /*point to arrays of terms of p1,p2 and sum resp*/
  while(i<p1.size && j<p2.size) /*procedure similar to merging of sorted arrays*/
  {
      if(p1.t[i].exp>p2.t[j].exp) /*highest power is taken first*/
      {
          sum->t[k]=p1.t[i];
          i++,k++;
      }
      else if(p1.t[i].exp<p2.t[j].exp)
      {
           sum->t[k]=p2.t[j];
           j++,k++;
      }
      else /*case of addition*/
      {
          sum->t[k]=p1.t[i];
          sum->t[k].coeff+=p2.t[j].coeff;
          i++,j++,k++;
      }
  }
  for(;i<p1.size;i++) /*missing elements of either one*/
  {
        sum->t[k]=p1.t[i];
        i++,k++;
  }
  for(;j<p2.size;j++)
  {
        sum->t[k]=p2.t[j];
        j++,k++;
  }
  sum->size=k; /*number of non zero terms for structure pointed to by sum is fixed*/
  return sum; /*address of structure pointed to by sum is returned*/

}
void display(struct poly p)
{
    int i;
    for(i=0;i<(p.size-1);i++)
    {
        printf("%d.x^%d+  ",p.t[i].coeff,p.t[i].exp); /*all terms except the last term*/
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




