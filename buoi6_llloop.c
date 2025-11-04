#include<stdio.h>
#include"buoi_5.h"

void NODEL_Init()
{
    current = NULL;
}

void NODEL_Add(Node* pre_node, int value)
{
    Node* new_node = malloc(sizeof(Node)); 
    if (new_node == NULL) return;

    new_node->value = value;
    if(current == NULL)
    {
        new_node->ptr_next = new_node;
        new_node->ptr_previous = new_node;
        head = tail = current = new_node;
        return;
    }

    new_node->ptr_previous = pre_node;
    new_node->ptr_next = pre_node->ptr_next;

    pre_node->ptr_next->ptr_previous = new_node;
    pre_node->ptr_next = new_node;

    current = new_node;
}

void NODEL_Del(Node* current_node)
{
    if(current == NULL) return;

    current_node->ptr_next->ptr_previous = current_node->ptr_previous;
    current_node->ptr_previous->ptr_next = current_node->ptr_next;

    free(current_node);
}

void NODEL_Display()
{
    if (current == NULL) 
    {
        printf("List empty.\n");
        return;
    }

    Node* temp = current;
    printf("Loop LL information:\n");
    do 
    {
        printf("Value: %d\n", temp->value);
        temp = temp->ptr_next;
    } while (temp != current);

    free(temp);
}

void NODEL_Modify(Node* current_node, int value)
{
    if(current == NULL) return;

    current_node->value = value;
}

int NODEL_Seek(Node* current_node)
{
    if(current == NULL) return 0;

    return current_node->value;
}

void NODEL_PositionChange(Node* first_node, Node* second_node)
{
    if (first_node == NULL || second_node == NULL) return;

    int tmp = first_node->value;
    first_node->value = second_node->value;
    second_node->value = tmp;
}

int main(){}