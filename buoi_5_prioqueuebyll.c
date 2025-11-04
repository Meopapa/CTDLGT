#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float value;
    struct Node* ptr_next;
} Node;

typedef struct QueueLL {
    Node* front;
    Node* rear;
} QueueLL;

void QUEUE_Init(QueueLL* q)
{
    q->front = q->rear = NULL;
}

int QUEUE_IsEmpty(QueueLL* q)
{
    return q->front == NULL;
}

void QUEUE_Add(QueueLL* q, float val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->value = val;
    newNode->ptr_next = NULL;

    if (QUEUE_IsEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->ptr_next = newNode;
        q->rear = newNode;
    }
}

float QUEUE_Get(QueueLL* q)
{
    if (QUEUE_IsEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = q->front;
    float val = temp->value;
    q->front = q->front->ptr_next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

float QUEUE_PeekFront(QueueLL* q)
{
    if (QUEUE_IsEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->value;
}

float QUEUE_PeekRear(QueueLL* q)
{
    if (QUEUE_IsEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->rear->value;
}

void QUEUE_Display(QueueLL* q)
{
    if (QUEUE_IsEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%.2f ", current->value);
        current = current->ptr_next;
    }
    printf("\n");
}

void QUEUE_Clear(QueueLL* q) {
    while (!QUEUE_IsEmpty(q)) {
        QUEUE_Get(q);
    }
}


int main()
{
    QueueLL q;
    QUEUE_Init(&q);

    QUEUE_Add(&q, 10.5);
    QUEUE_Add(&q, 20.7);
    QUEUE_Add(&q, 30.2);

    QUEUE_Display(&q);

    printf("Front = %.2f\n", QUEUE_PeekFront(&q));
    printf("Rear  = %.2f\n", QUEUE_PeekRear(&q));

    printf("Dequeued: %.2f\n", QUEUE_Get(&q));
    QUEUE_Display(&q);

    printf("Dequeued: %.2f\n", QUEUE_Get(&q));
    QUEUE_Display(&q);

    printf("Dequeued: %.2f\n", QUEUE_Get(&q));
    QUEUE_Display(&q);

    return 0;
}
