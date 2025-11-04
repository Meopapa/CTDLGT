#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#define MAX 50

typedef struct Cell
{
    float num;
    char* str;
}Cell;

typedef struct Queue
{
    float infor[MAX];
    Cell information[MAX];
    int front;
    int rear;
}Queue;

void QUEUE_Init(Queue* q);
int QUEUE_IsEmpty(Queue* q);
int QUEUE_IsFull(Queue* q);
void QUEUE_Add(Queue* q, float val);
float QUEUE_Get(Queue* q);
float QUEUE_PeekFront(Queue* q);
float QUEUE_PeekRear(Queue* q);
void QUEUE_Display(Queue* q);

void QUEUE_InitLoop(Queue* q);
int QUEUE_IsEmptyLoop(Queue* q);
int QUEUE_IsFullLoop(Queue* q);
void QUEUE_AddLoop(Queue* q, float val);
float QUEUE_GetLoop(Queue* q);
float QUEUE_PeekFrontLoop(Queue* q);
float QUEUE_PeekRearLoop(Queue* q);
void QUEUE_DisplayLoop(Queue* q);

#endif

