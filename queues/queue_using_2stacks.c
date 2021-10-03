#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    int* p;
};
struct stack* create(int);
void push(struct stack*,int);
int pop(struct stack*);
int stacktop(struct stack*);
int isempty(struct stack*);
void enqueue(int);
int dequeue();
struct stack *st1,*st2;
int main()
{
    int size;
    printf("enter the size of the queue: \n");
    scanf("%d",&size);
    st1=create(size); /*enqueue stack*/
    st2=create(size); /*dequeue stack*/
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    printf("the order in which the elements leave the queue: \n");
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    enqueue(7);
    enqueue(8);
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    enqueue(9);
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("we can see that this is the same order in which they entered the queue so FIFO principle is followed \n");

}
struct stack* create(int x)
{
    struct stack* st;
    st=(struct node*)malloc(sizeof(struct stack));
    st->size=x;
    st->top=-1;
    st->p=(int*)malloc(st->size*sizeof(int));
    return st;
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
        int x=st->p[st->top];
        st->top--;
        return x;
    }
}
void enqueue(int x)
{
    if(st1->top==st1->size-1)
    {
        printf("queue overflow \n");
        return;
    }
    else
    {
        push(st1,x);
    }
}
int dequeue()
{
    if(isempty(st2)==1) /*stack 2 is empty*/
    {
        if(isempty(st1)==1)
        {
            printf("queue underflow \n");
            return;
        }
        else /*pop all elements from stack 1 to stack 2 till stack 1 is empty and return the top of stack 2*/
        {
            while(isempty(st1)!=1)
            {
                push(st2,pop(st1));
            }
            return pop(st2);
        }
    }
    else /*stack 2 is not empty*/
    {
        return pop(st2);
    }
}
int isempty(struct stack* st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int stacktop(struct stack* st)
{
    if(st->top==-1)
    {
        printf("stack is empty \n");
        return;
    }
    else
    {
        return st->p[st->top];
    }
}
