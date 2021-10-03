#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct queue
{
    int size;
    int front;
    int rear;
    int* p;
};
struct queue *q;
void enqueue(struct queue*,int);
int dequeue(struct queue*);
void display(struct queue*);
struct queue* create(int); /*takes size as the input*/
int front(struct queue*);
int rear(struct queue*);
int isempty(struct queue*);
int isfull(struct queue*);
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
    enqueue(q,10);
    printf("the queue is: \n");
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printf("now the queue is: \n");
    display(q);
    printf("the element at the front is: %d \n",front(q));
    printf("the element at the rear is: %d \n",rear(q));
    isempty(q)==1?printf("the queue is empty \n"):printf("the queue is not empty \n");
    isfull(q)==1?printf("the queue is full \n"):printf("the queue is not full \n");

}
struct queue* create(int x)
{
    struct queue* m;
    m=(struct queue*)malloc(sizeof(struct queue)); /*queue is created*/
    m->size=x;
    m->front=m->rear=-1;
    m->p=(int*)malloc(m->size*sizeof(int));
    /*queue is initialized*/
    return m;
}
void enqueue(struct queue* m,int x)
{
    if(m->front==m->size-1) /*queue is full*/
    {
        printf("queue overflow \n");
        return;
    }
    else
    {
        m->rear++;
        m->p[m->rear]=x;
    }
}
void display(struct queue* m)
{
    int i=m->front;
    i++; /*queue starts from the next index of front*/
    for(;i<=m->rear;i++)
    {
        printf("%d \n",m->p[i]);
    }
}
int dequeue(struct queue* m)
{
    if(m->front==m->rear) /*condition of empty queue*/
    {
        printf("stack underflow \n");
        return -1;
    }
    else
    {
        int x=m->p[m->front+1]; /*queue starts from the next index of front*/
        m->front++;
        return x;
    }
}
int front(struct queue* m)
{
    if(m->front==m->rear) /*queue is empty*/
    {
        printf("the queue is empty \n");
        return -1;
    }
    else
    {
        int x=m->p[m->front+1];
        return x;
    }

}
int rear(struct queue* m)
{
    if(m->front==m->rear) /*queue is empty*/
    {
        printf("the queue is empty \n");
        return -1;
    }
    else
    {
        int x=m->p[m->rear];
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
    if(m->rear==m->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
