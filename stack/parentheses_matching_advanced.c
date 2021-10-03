#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    char *c;
};
int isempty(struct stack);
void push(struct stack*,char);
void pop(struct stack*);
char stacktop(struct stack);
int isbalanced(char t[]);
int main()
{
    char expression[100];
    printf("enter your expression to check for parentheses matching: \n");
    scanf("%s",expression);
    isbalanced(expression)==1?printf("the expression has balanced parentheses \n"):printf("the expression does not have balanced parentheses");
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
char stacktop(struct stack st)
{
    if(st.top==-1)
    {
        return '\0';
    }
    else
    {
        return st.c[st.top];
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
        if(t[i]=='('||t[i]=='['||t[i]=='{')
            {
                push(&st,t[i]);
            }
        if(t[i]==')'||t[i]==']'||t[i]=='}') /*case of pop*/
        {
            if(isempty(st)==1) /*we can not pop as stack is empty*/
            {
                return 0;
            }
            if(t[i]-stacktop(st)<=2) /*brackets have matched-the bracket at top is the counterpart of the bracket*/
            {
                pop(&st);
            }
            else
            {
                return 0;
            }
        }
    }
    if(isempty(st)==1) /*case of perfectly balanced*/
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
