#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "include\data_structure.h"

#define QUEUE_DECLARE_INIT(type, number) \
    int QUEUE_Init_##type(Queue_##type##_##number *q);
#define QUEUE_DECLARE_CHECK(type, number) \
    int QUEUE_IsFull_##type(Queue_##type##_##number *q); \
    int QUEUE_IsEmpty_##type(Queue_##type##_##number *q);
#define QUEUE_DECLARE_ACT(type, number) \
    int QUEUE_Enqueue_##type(Queue_##type##_##number *q, type n); \
    type QUEUE_Dequeue_##type(Queue_##type##_##number *q); \
    type QUEUE_Peek_##type(Queue_##type##_##number *q); 
#endif