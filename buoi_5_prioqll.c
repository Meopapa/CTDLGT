#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    float value;
    int priority;
    struct Node* ptr_next;
} Node;

typedef struct QueueLL 
{
    Node* front;  
    Node* rear;   
    Node* head;   
} QueueLL;

void QUEUE_Init(QueueLL* q)
{
    q->front = q->rear = q->head = NULL;
}

int QUEUE_IsEmpty(QueueLL* q)
{
    return q->head == NULL;
}

void QUEUE_Add(QueueLL* q, float val, int priority)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) 
    {
    printf("Memory allocation failed!\n");
    return;
    }
    
    newNode->value = val;
    newNode->priority = priority;
    newNode->ptr_next = NULL;

    if (QUEUE_IsEmpty(q)) q->front = q->rear = q->head = newNode;
    else 
    {
        q->rear->ptr_next = newNode;
        q->rear = newNode;

        if (priority > q->front->priority) q->front = newNode;
    }
}

float QUEUE_Get(QueueLL* q)
{
    if (QUEUE_IsEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* current = q->head;
    Node* prev = NULL;

    Node* maxNode = current;
    Node* prevMax = NULL;

    while (current != NULL) {
        if (current->priority > maxNode->priority) 
        {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->ptr_next;
    }

    if (prevMax == NULL) q->head = maxNode->ptr_next;
    else prevMax->ptr_next = maxNode->ptr_next;

    if (maxNode == q->rear) q->rear = prevMax;

    float val = maxNode->value;
    free(maxNode);

    Node* temp = q->head;
    Node* newFront = temp;
    while (temp != NULL) 
    {
        if (temp->priority > newFront->priority) newFront = temp;
        temp = temp->ptr_next;
    }
    q->front = newFront;

    return val;
}

float QUEUE_PeekFront(QueueLL* q) 
{
    if (QUEUE_IsEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->value;
}

void QUEUE_Display(QueueLL* q)
{
    if (QUEUE_IsEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return;
    }

    Node* current = q->head;
    printf("Queue:\n");
    while (current != NULL) 
    {
        printf("Value: %.2f, Priority: %d\n", current->value, current->priority);
        current = current->ptr_next;
    }
    printf("Front -> Value: %.2f (Priority %d)\n\n", q->front->value, q->front->priority);
}

void QUEUE_Clear(QueueLL* q) {
    while (!QUEUE_IsEmpty(q)) 
    {
        QUEUE_Get(q);
    }
}

int main()
{
    QueueLL q;
    QUEUE_Init(&q);

    QUEUE_Add(&q, 10.5, 2);
    QUEUE_Add(&q, 5.5, 1);
    QUEUE_Add(&q, 99.9, 5);  
    QUEUE_Add(&q, 33.3, 3);

    QUEUE_Display(&q);

    return 0;
}
