#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char* c;
};
void push(struct stack*,char);
void pop(struct stack*);
int isempty(struct stack);
int main()
{
    char expression[1000];
    int isbalanced(char t[]);
    printf("enter the expression to check for balanced parentheses: \n");
    scanf("%s",expression);
    isbalanced(expression)==1?printf("the expression has balanced parentheses \n"):printf("the expression does not have balanced parentheses \n");
}
void push(struct stack* st,char a)
{
    if(st->top==st->size-1)
    {
        printf("stack overflow \n");
        return;
    }
    else
    {
        st->top++;
        st->c[st->top]=a;
    }
}
void pop(struct stack* st)
{
    if(st->top==-1)
    {
        printf("stack underflow \n");
        return;
    }
    else
    {
        st->top--;
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
int isbalanced(char t[])
{
    struct stack st;
    st.top=-1;
    st.size=strlen(t);
    st.c=(char*)malloc(st.size*sizeof(char));
    int i;
    for(i=0;t[i]!='\0';i++)
    {
        if(t[i]=='(')
        {
            push(&st,t[i]);
        }
        if(t[i]==')')
        {
            if(isempty(st)==1)
            {
                return 0;
            }
            else
            {
                pop(&st);
            }
        }
    }
    if(isempty(st)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

