#include <stdio.h>
#include <stdlib.h>
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

void QUEUE_Add(Queue* q, float num, char* str)
{
    if(QUEUE_IsFull(q)) return;
    q->information[q->rear++] = (Cell){num, str};
}

float QUEUE_GetID(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return 0;
    return q->information[++q->front].num;
}

char* QUEUE_GetStr(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return NULL;
    return q->information[++q->front].str;
}

Cell QUEUE_PeekFront(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return (Cell){0, NULL};
    return q->information[q->front];
}

Cell QUEUE_PeekRear(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return (Cell){0, NULL};
    return q->information[q->rear];
}

void QUEUE_Display(Queue* q)
{
    if(QUEUE_IsEmpty(q)) return;
    for(int i = q->front; i <= q->rear; i++)
    {
        printf("%f, ", q->information[i].num);
        printf("%s\n", q->information[i].str);
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