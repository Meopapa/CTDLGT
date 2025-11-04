#include <stdio.h>
#include <string.h>
#include "buoi_5.c"

Node* node_find = NULL;

void insertProcess(Node* pre, Node* next, int prio, char* id, char* name, enum STATUS status)
{   
    NODE_Add(pre, next, prio, 0);

    if(current == NULL) return;

    strncpy(current->id, id, sizeof(current->id) - 1);
    current->id[sizeof(current->id) - 1] = '\0';

    strncpy(current->name, name, sizeof(current->name) - 1);
    current->name[sizeof(current->name) - 1] = '\0';

    current->status = status;

    if(!(current->status) && (node_find == NULL || prio >= node_find->value)) node_find = current; //findReadyHighestPriority
}

void removeProcess()
{
    NODE_Del(node_find);
}

void removeAllTerminated()
{
    Node* del = head;
    while (del != NULL) 
    {
        Node* next = del->ptr_next;
        if (del->status == TERMINATED) NODE_Del(del);
        del = next;
    }
}

int main() 
{
    NODE_Init();

    insertProcess(NULL, NULL, 3, "P1", "Process 1", READY);
    insertProcess(tail, NULL, 5, "P2", "Process 2", RUNNING);
    insertProcess(tail, NULL, 2, "P3", "Process 3", READY);
    insertProcess(tail, NULL, 4, "P4", "Process 4", TERMINATED);
    insertProcess(tail, NULL, 1, "P5", "Process 5", WAITING);
    insertProcess(tail, NULL, 6, "P6", "Process 6", TERMINATED);

    printf("\nDanh sach tien trinh:\n");
    NODE_Display();

    if (node_find != NULL) 
    {
        printf("\nTien trinh READY uu tien cao nhat:\n");
        printf("ID: %s\nName: %s\nPriority: %d\n", node_find->id, node_find->name, node_find->value);
    } 
    else 
    {
        printf("\nKhong co READY.\n");
    }

    printf("\nXoa READY cao nhat\n");
    removeProcess();

    printf("\nXoa het TERMINATED\n");
    removeAllTerminated();

    printf("\nDanh sach moi:\n");
    NODE_Display();

    NODE_Cleanup();

    return 0;
}