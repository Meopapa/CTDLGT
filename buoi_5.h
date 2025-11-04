#ifndef BUOI_5
#define BUOI_5

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_STR 100
#define MAX_NODE 100

enum STATUS{READY = 0, RUNNING = 1, WAITING = 2, TERMINATED = 3};

typedef struct Node
{
    int value;
    float val;
    char name[100], id[MAX_STR/10];
    enum STATUS status;
    struct Node *ptr_next, *ptr_previous;
}Node;

extern Node *head; 
extern Node *tail;
extern Node *current;

void NODE_Init();
float NODE_Seek(Node *seek_node, bool isInt);
void NODE_Add(Node *pre_node, Node *next_node, int val, float flt);
void NODE_Del(Node *old_node);
void NODE_Modify(Node *modify_node, int value, float val);
void NODE_Display();
const char* statusToString(enum STATUS s);
void NODE_PositionChange(Node *node_1, Node *node_2);
void NODE_Cleanup();

void NODEL_Add(Node* pre_node, int value);
void NODEL_Init();
void NODEL_Del(Node* current_node);
void NODEL_Display();
void NODEL_Modify(Node* current_node, int value);
int NODEL_Seek(Node* current_node);
void NODEL_PositionChange(Node* first_node, Node* second_node);

#endif