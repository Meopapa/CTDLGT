#include "data_structure/data_structure.h"
#include "data_structure/dsa_configs.h"
#include "data_structure/queue.h"

#define QUEUE_IMPLEMENT_INIT(type, number) \
    int QUEUE_Init_##type(Queue_##type##_##number *q) \
    { \
        if(q == NULL) return ERROR_NULL_PTR; \
        q->front = q->rear = 0; \
        q->count = 0; \
        return SUCCESS_TRUE; \
    }
#define QUEUE_IMPLEMENT_CHECK(type, number) \
    int QUEUE_IsFull_##type(Queue_##type##_##number *q) \
    { \
        if(q == NULL) return ERROR_NULL_PTR; \
        return ((q->front == q->rear) && (q->count == number))? SUCCESS_TRUE : FAIL_FALSE; \
    } \
    int QUEUE_IsEmpty_##type(Queue_##type##_##number *q) \
    { \
        if(q == NULL) return ERROR_NULL_PTR; \
        return ((q->front == q->rear) && !(q->count))? SUCCESS_TRUE : FAIL_FALSE; \
    }
#define QUEUE_IMPLEMENT_ACT(type, number) \
    int QUEUE_Enqueue_##type(Queue_##type##_##number *q, type n) \
    { \
        if(q == NULL) return ERROR_NULL_PTR; \
        if(QUEUE_IsFull_##type(q)) return FAIL_FALSE; \
        q->data[q->rear] = n; \
        q->rear = (q->rear + 1) % number; \
        q->count++; \
        return SUCCESS_TRUE; \
    } \
    type QUEUE_Dequeue_##type(Queue_##type##_##number *q) \
    { \
        if(q == NULL) return (type)ERROR_NULL_PTR; \
        if(QUEUE_IsEmpty_##type(q)) return (type)FAIL_FALSE; \
        type dequeue = q->data[q->front]; \
        q->front = (q->front + 1) % number; \
        q->count--; \
        return dequeue; \
    } \
    type QUEUE_Peek_##type(Queue_##type##_##number *q) \
    { \
        if(q == NULL) return (type)ERROR_NULL_PTR; \
        if(QUEUE_IsEmpty_##type(q)) return (type)ERROR_EMPTY; \
        return q->data[q->front]; \
    }

#define QUEUE_IMPLEMENTATION_END 1

QUEUE_STRUCT(int, 8)
QUEUE_IMPLEMENT_INIT(int, 8)
QUEUE_IMPLEMENT_CHECK(int, 8)
QUEUE_IMPLEMENT_ACT(int, 8)
