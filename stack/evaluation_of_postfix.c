#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    int* p; /*stack will hold integer values-operand and not the operators*/
};
void push(struct stack*,int);
int pop(struct stack*);
int isempty(struct stack);
int isoperand(char);
int stacktop(struct stack);
int evaluate(char postfix[]);
int main()
{
    char expression[1000];
    printf("enter the postfix form of your expression to be calculated: \n");
    scanf("%s",expression);
    printf("the value of the expression: %d \n",evaluate(expression));
}
void push(struct stack* st,int x)
{
    if(st->top==st->size-1)
    {
        printf("stack overflow \n");
        return;
    }
    else
    {
        st->top++;
        st->p[st->top]=x;
    }
}
int pop(struct stack* st)
{
    if(st->top==-1)
    {
        printf("stack underflow \n");
        return;
    }
    else
    {
        int x;
        x=st->p[st->top];
        st->top--;
        return x;
    }
}
int isempty(struct stack st)
{
    if(st.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isoperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/') /*case of operator*/
    {
        return 0;
    }
    else /*case of operand*/
    {
        return 1;
    }
}
int stacktop(struct stack st)
{
    if(st.top==-1)
    {
        return -1;
    }
    else
    {
        return st.p[st.top];
    }
}
int evaluate(char postfix[])
{
    struct stack st;
    st.top=-1;
    st.size=strlen(postfix);
    st.p=(int*)malloc(st.size*sizeof(int)); /*stack declared and initialized*/
    int i,x1,x2,r;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isoperand(postfix[i])==1) /*case of operand which are to be pushed onto the stack*/
        {
            push(&st,postfix[i]-48); /*conversion to int*/
        }
        else /*case of operator when the top two elements have to be popped and the result of the operation has to be pushed*/
        {
            x2=pop(&st); /*top operand comes on the right hand side of the operation*/
            x1=pop(&st);
            char c=postfix[i];
            switch(c)
            {
                case '+': r=x1+x2;
                push(&st,r);
                break;
                case '-': r=x1-x2;
                push(&st,r);
                break;
                case '*': r=x1*x2;
                push(&st,r);
                break;
                case '/': r=x1/x2;
                push(&st,r);
                break;
            }
        }
    }
    return pop(&st);
}
