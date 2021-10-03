#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct queue
{
    int size;
    int front;
    int rear;
    int* a;
};
struct queue* q;
struct queue* create(int); /*takes the size as the input*/
void enqueue(struct queue*,int);
int dequeue(struct queue*);
int isempty(struct queue*);
int isfull(struct queue*);
void display(struct queue*);
int first(struct queue* m);
int last(struct queue* m);
int main()
{
    q=create(10);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);
    enqueue(q,9);
    printf("the queue is: \n");
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printf("the queue now is: \n");
    display(q);
    printf("the front element is: %d \n",first(q));
    printf("the last element is: %d \n",last(q));
    isempty(q)==1?printf("the list is empty \n"):printf("the list is not empty \n");
    isfull(q)==1?printf("the list if full \n"):printf("the list is not full \n");
}
struct queue* create(int x)
{
    struct queue* m;
    m=(struct queue*)malloc(sizeof(struct queue)); /*queue created*/
    m->size=x;
    m->front=m->rear=0;
    m->a=(int*)malloc(m->size*sizeof(int));
}
void enqueue(struct queue* m,int x)
{
    if((m->rear+1)%m->size==m->front) /*full condition-the next of rear is front*/
    {
        printf("queue overflow \n");
        return;
    }
    else
    {
        m->rear=(m->rear+1)%m->size; /*to move rear circularly*/
        m->a[m->rear]=x;
    }
}
void display(struct queue* m)
{
    int i=(m->front+1)%m->size; /*queue starts from the next of front pointer*/
    while(i!=(m->rear+1)%m->size)
    {
        printf("%d \n",m->a[i]);
        i=(i+1)%m->size;
    }
}
int dequeue(struct queue* m)
{
    if(m->front==m->rear) /*empty condition*/
    {
        printf("queue underflow \n");
        return;
    }
    else
    {
        m->front=(m->front+1)%m->size;
        int x=m->a[m->front];
        return x;
    }
}
int isempty(struct queue* m)
{
    if(m->front==m->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct queue* m)
{
    if((m->rear+1)%m->size==m->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int first(struct queue* m)
{
    if(isempty(m)==1)
    {
        printf("the list is empty \n");
        return;
    }
    else
    {
        int i=(m->front+1)%m->size;
        return m->a[i];
    }
}
int last(struct queue* m)
{
    if(isempty(m)==1)
    {
        printf("the list is empty \n");
        return;
    }
    else
    {
        return m->a[m->rear];
    }
}
