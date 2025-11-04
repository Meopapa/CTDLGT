#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "buoi_5.h"

Node *head;
Node *tail;
Node *current;

void NODE_Init()
{
    head = tail = current = NULL;
}

void NODE_Add(Node *pre_node, Node *next_node, int val, float flt)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return;

    new_node->value = val;
    new_node->val = flt;
    new_node->ptr_previous = pre_node;
    new_node->ptr_next = next_node;

    if (pre_node != NULL) pre_node->ptr_next = new_node;
    else head = new_node;  

    if (next_node != NULL) next_node->ptr_previous = new_node;
    else tail = new_node;
    
    current = new_node;
}

void NODE_Del(Node *old_node)
{
    if (old_node == NULL) return;

    if (old_node->ptr_previous != NULL) old_node->ptr_previous->ptr_next = old_node->ptr_next;
    else head = old_node->ptr_next; 

    if (old_node->ptr_next != NULL) old_node->ptr_next->ptr_previous = old_node->ptr_previous;
    else tail = old_node->ptr_previous; 

    free(old_node);
}

void NODE_Display()
{
    Node *display_node = head;

    if (head == NULL && tail == NULL) return;
    printf("Displaying node information:\n");

    while (display_node != NULL)
    {
        printf("Node information:\n");
        printf("1. value: %d\n", display_node->value);
        printf("2. float val: %.2f\n", display_node->val);
        printf("3. status: %s\n", statusToString(display_node->status));
        printf("4. id: %s\n", display_node->id);
        printf("5. name: %s\n", display_node->name);
        display_node = display_node->ptr_next;
    }
}

const char* statusToString(enum STATUS s) 
{
    switch (s) 
    {
        case READY: return "READY";
        case RUNNING: return "RUNNING";
        case WAITING: return "WAITING";
        case TERMINATED: return "TERMINATED";
        default: return "UNKNOWN";
    }
}

void NODE_Modify(Node *modify_node, int value, float val)
{
    if(head == NULL && tail == NULL) return;
    modify_node->val = val;
    modify_node->value = value;
}

float NODE_Seek(Node *seek_node, bool isInt)
{
    if(head == NULL && tail == NULL) return 0;
    return (isInt) ? ((float)seek_node->value) : (seek_node->val);
}

void NODE_PositionChange(Node *node_1, Node *node_2)
{
    if(head == NULL && tail == NULL) return;
    int temp = node_1->value;
    node_1->value = node_2->value;
    node_2->value = temp;

    float temp_ = node_1->val;
    node_1->val = node_2->val;
    node_2->val = temp_;
}

void NODE_SetCurrent(Node *node)
{
    current = node;
}

void NODE_Cleanup() 
{
    Node *temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->ptr_next;
        free(temp);
    }
    tail = current = NULL;
}

// void NODE_SortByVal()
// {}

// int main()
// {
//     NODE_Init();
//     NODE_Add(NULL, NULL, 5, 10.5);
//     NODE_Add(tail, NULL, 3, 7.2);
//     NODE_Add(tail, NULL, 8, 15.3);
//     NODE_Display();
//     return 0;
// }