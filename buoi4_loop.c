#include<stdio.h>
#include "buoi4.h"

void QUEUE_InitLoop(Queue* q)
{
    q->front = q->rear = -1;
}

int QUEUE_IsEmptyLoop(Queue* q)
{
    return (q->front == -1);
}

int QUEUE_IsFullLoop(Queue* q)
{
    return (q->rear - q->front == MAX - 1 || q->front^q->rear == 1);
}

void QUEUE_AddLoop(Queue* q, float val)
{
    if(QUEUE_IsFullLoop(q)) return;
    q->infor[(q->rear++)%MAX] = val;
}

float QUEUE_GetLoop(Queue* q)
{
    if(QUEUE_IsEmptyLoop(q)) return 0;
    return q->infor[(++q->front)%MAX];
}

float QUEUE_PeekFront(Queue* q)
{
    if(QUEUE_IsEmptyLoop(q)) return 0;
    return q->infor[q->front];
}

float QUEUE_PeekRear(Queue* q)
{
    if(QUEUE_IsEmptyLoop(q)) return 0;
    return q->infor[q->rear];
}

void QUEUE_Display(Queue* q)
{
    if(QUEUE_IsEmptyLoop(q)) return;
    if(q->front>q->rear)
    {
        for(int i = q->front; i < MAX; i++)
        {
            printf("%f", q->infor[i]);
        }
        for(int i = 0; i <= q->rear; i++)
        {
            printf("%f", q->infor[i]);
        }
    }
    else
    {
        for(int i = q->front; i <= q->rear; i++)
        {
            printf("%f", q->infor[i]);
        }
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
    QUEUE_InitLoop(&q);
    QUEUE_AddLoop(&q, value);
    QUEUE_AddLoop(&q, val1);
    QUEUE_AddLoop(&q, val2);
    QUEUE_DisplayLoop(&q);
    QUEUE_GetLoop(&q);
    QUEUE_DisplayLoop(&q);
    QUEUE_PeekFrontLoop(&q);
    QUEUE_PeekRearLoop(&q);
}
*/