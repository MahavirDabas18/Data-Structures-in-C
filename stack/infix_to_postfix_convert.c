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
char pop(struct stack*);
int isempty(struct stack);
int isoperand(char);
int pre(char);
char stacktop(struct stack);
char* convert(char infix[]);
int main()
{
    char expression[1000];
    printf("enter the infix expression for conversion to postfix form: \n");
    scanf("%s",expression);
    printf("the postfix form of the expression will be: \n");
    printf("%s \n",convert(expression));

}
void push(struct stack* st,char x)
{
    if(st->top==st->size-1)
    {
        printf("stack overflow \n");
        return;
    }
    else
    {
        st->top++;
        st->c[st->top]=x;
    }
}
char pop(struct stack* st)
{
    if(st->top==-1)
    {
        printf("stack underflow \n");
        return;
    }
    else
    {
        char x=st->c[st->top];
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
    if(x=='+'||x=='-'||x=='*'||x=='/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int pre(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char stacktop(struct stack st)
{
    if(st.top==-1)
    {
        return -1;
    }
    else
    {
        return st.c[st.top];
    }
}
char* convert(char infix[])
{
    struct stack st;
    st.top=-1;
    st.size=strlen(infix);
    st.c=(char*)malloc(st.size*sizeof(char)); /*stack created and initialized*/
    char* postfix;
    postfix=(char*)malloc((strlen(infix)+1)*sizeof(char)); /*postfix expression will be one more than  string length as it will end with an extra null char*/
    int i=0; /*to track infix*/
    int j=0; /*to track postfix*/
    while(infix[i]!='\0')
    {
        if(isoperand(infix[i])==1) /*case of operand to be added to postfix*/
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else /*case of operator*/
        {
            if(pre(infix[i])>pre(stacktop(st))) /*operator will be pushed only if precedence is higher*/
            {
                push(&st,infix[i]);
                i++;
            }
            else /*when stack top has equal to or higher precedence it will be added to postfix*/
            {
                char x=pop(&st);
                postfix[j]=x;
                j++;
                /*i is not incremented as it will be checked again and again till the operator can be pushed onto the stack*/
            }
        }
    }
    while(isempty(st)!=1)
    {
        char z=pop(&st);
        postfix[j]=z;
        j++;
    }
    postfix[j]='\0'; /*addition of null character so that postfix is converted to string*/
    return postfix;
}
