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
    return ((q->rear + 1) % MAX == q->front);
}

void QUEUE_AddLoop(Queue* q, float val)
{
    if (QUEUE_IsFullLoop(q))
    {
        printf("Queue is full!\n");
        return;
    }

    if (QUEUE_IsEmptyLoop(q)) q->front = q->rear = 0;
    else q->rear = (q->rear + 1) % MAX;

    q->infor[q->rear] = val;
}

float QUEUE_GetLoop(Queue* q)
{
    if (QUEUE_IsEmptyLoop(q))
    {
        printf("Queue is empty!\n");
        return 0; 
    }

    float val = q->infor[q->front];
    if (q->front == q->rear) q->front = q->rear = -1; 
    else q->front = (q->front + 1) % MAX;

    return val;
}

float QUEUE_PeekFrontLoop(Queue* q)
{
    if(QUEUE_IsEmptyLoop(q)) return 0;
    return q->infor[q->front];
}

float QUEUE_PeekRearLoop(Queue* q)
{
    if(QUEUE_IsEmptyLoop(q)) return 0;
    return q->infor[q->rear];
}

void QUEUE_DisplayLoop(Queue* q)
{
    if(QUEUE_IsEmptyLoop(q)) return;
    if(q->front>q->rear)
    {
        for(int i = q->front; i < MAX; i++)
        {
            printf("%.2f\n", q->infor[i]);
        }
        for(int i = 0; i <= q->rear; i++)
        {
            printf("%.2f\n", q->infor[i]);
        }
    }
    else
    {
        for(int i = q->front; i <= q->rear; i++)
        {
            printf("%.2f\n", q->infor[i]);
        }
    }
}

int main()
{
    Queue q;
    float value = 1, val1 = 2, val2 = 3;

    QUEUE_InitLoop(&q);

    QUEUE_AddLoop(&q, value);
    QUEUE_AddLoop(&q, val1);
    QUEUE_AddLoop(&q, val2);
    QUEUE_DisplayLoop(&q);

    QUEUE_GetLoop(&q);
    QUEUE_DisplayLoop(&q);

    printf("Front: %.2f\n", QUEUE_PeekFrontLoop(&q));
    printf("Rear: %.2f\n", QUEUE_PeekRearLoop(&q));

    return 0;
}
