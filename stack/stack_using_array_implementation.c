#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct stack
{
    int top;
    int size;
    int *s;
};

int main()
{
    struct stack st; /*struct stack is created*/
    void create(struct stack*);
    void push(struct stack*,int);
    int pop(struct stack*);
    int peek(struct stack,int);
    void display(struct stack);
    int stacktop(struct stack);
    int isfull(struct stack);
    int isempty(struct stack);
    create(&st); /*call by address as modifications will be made*/
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    push(&st,5);
    pop(&st);
    pop(&st);
    printf("the stack is: \n");
    display(st);
    printf("the element at 2nd position is: %d \n",peek(st,2));
    printf("the element at the top of the stack is: %d \n",stacktop(st));
    pop(&st);
    pop(&st);
    pop(&st);
    isempty(st)==1?printf("the stack is empty \n"):printf("the stack is not empty \n");
    isfull(st)==1?printf("the stack is full \n"):printf("the stack is not full \n");
}
void create(struct stack* st)
{
    printf("enter size of the stack to be created: \n");
    scanf("%d",&st->size); /*size initialized*/
    st->top=-1; /*top initialized*/
    st->s=(int*)malloc(st->size*sizeof(int)); /*array to which structure points created*/
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
        st->s[st->top]=x;
    }
}
int peek(struct stack st,int pos)
{
    if(st.top-pos+1<0 || st.top-pos+1>st.size)
    {
        printf("invalid position \n");
        return;
    }
    else
    {
        return st.s[st.top-pos+1];
    }
}
void display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d \n",st.s[i]);
    }
}
int pop(struct stack* st)
{
    int x;
    if(st->top==-1)
    {
        printf("stack underflow \n");
        return;
    }
    else
    {
        x=st->s[st->top];
        st->top--;
        return x;
    }
}
int stacktop(struct stack st)
{
    if(st.top==-1) /*case of empty stack*/
    {
        return -1;
    }
    else
    {
        return st.s[st.top];
    }
}
int isfull(struct stack st)
{
    if(st.top==st.size-1)
    {
        return 1;
    }
    else
    {
        return 0;
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
