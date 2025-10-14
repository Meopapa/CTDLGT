#include<stdio.h>
#include "buoi4.h"

void QUEUE_init(Queue* q)
{
    q->front = q->rear = -1;
}

int QUEUE_IsEmpty(Queue* q)
{
    return (q->front == -1);
}

int QUEUE_IsFull(Queue* q)
{
    return (q->rear == MAX - 1);
}

void QUEUE_Add(Queue* q, float val)
{
    if(QUEUE_IsFull(q)) return;
    q->infor[q->rear++] = val;
}

float QUEUE_Get(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return 0;
    return q->infor[++q->front];
}

float QUEUE_PeekFront(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return 0;
    return q->infor[q->front];
}

float QUEUE_PeekRear(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return 0;
    return q->infor[q->rear];
}

void QUEUE_Display(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return;
    for(int i = q->front; i <= q->rear; i++)
    {
        printf("%f", q->infor[i]);
    }
}
/*
int main()
{
    Queue q;
    float value, val1, val2;
    value = 1;
    val1 = 2;
    val2 = 3;
    QUEUE_Init(&q);
    QUEUE_Add(&q, value);
    QUEUE_Add(&q, val1);
    QUEUE_Add(&q, val2);
    QUEUE_Display(&q);
    QUEUE_Get(&q);
    QUEUE_Display(&q);
    QUEUE_PeekFront(&q);
    QUEUE_PeekRear(&q);
}
*/