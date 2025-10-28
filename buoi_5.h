#ifndef BUOI_5
#define BUOI_5

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_STR 100
#define MAX_ARR 100
#define MAX_NODE 100
#define NODE_SIZE 36 

typedef struct Node
{
    int value;
    float val;
    struct Node *ptr_next, *ptr_previous;
}Node;

extern Node *head; 
extern Node *tail;

void NODE_Init();
float NODE_Seek(Node *seek_node, bool isInt);
void NODE_Add(Node *pre_node, Node *next_node, int val, float flt);
void NODE_Del(Node *old_node, Node *pre_old_node, Node *next_old_node);
void NODE_Modify(Node *modify_node, int value, float val);
void NODE_Display();
void NODE_PositionChange(Node *node_1, Node *node_2, Node *pre_node_1, Node *next_node_1, Node *pre_node_2, Node *next_node_2);
void NODE_SortByVal();

#endif