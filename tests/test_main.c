#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "algorithm/search.h"
#include "algorithm/sort.h"
#include "algorithm/graph.h"
#include "algorithm/tree_balance.h"
#include "data_structure/array.h"
#include "data_structure/data_structure.h"
#include "data_structure/heap.h"
#include "data_structure/list.h"
#include "data_structure/queue.h"
#include "data_structure/stack.h"
#include "data_structure/tree.h"

STACK_STRUCT(int, 8)
STACK_DECLARE_INIT(int, 8)
STACK_DECLARE_CHECK(int, 8)
STACK_DECLARE_ATC(int, 8)

QUEUE_STRUCT(int, 8)
QUEUE_DECLARE_INIT(int, 8)
QUEUE_DECLARE_CHECK(int, 8)
QUEUE_DECLARE_ACT(int, 8)

TREE_STRUCT(int)
TREE_DECLARE_INIT(int)
TREE_DECLARE_ACT(int)
ROTATION_DECLARE(int)

TENSOR_STRUCT(int, 3)
TENSOR_DECLARE_INIT(int, 3)
TENSOR_DECLARE_LOCATE(int, 3)
TENSOR_DECLARE_TRANSPOSE(int, 3)

HEAP_STRUCT(int, 16)
HEAP_DECLARE(int, 16)

LIST_STRUCT(int, int, int)
LIST_DECLARE(int, int, int)

SEARCH_DECLARE(int)
SORT_DECLARE(int)

static void test_stack(void)
{
    Stack_int_8 stack;
    int value;

    assert(STACK_Init_int(&stack) == SUCCESS_TRUE);
    assert(STACK_IsEmpty_int(&stack) == SUCCESS_TRUE);
    assert(STACK_Push_int(&stack, 10) == SUCCESS_TRUE);
    assert(STACK_Push_int(&stack, 20) == SUCCESS_TRUE);
    assert(STACK_Top_int(&stack) == 20);
    value = STACK_Pop_int(&stack);
    assert(value == 20);
    assert(STACK_Pop_int(&stack) == 10);
    assert(STACK_IsEmpty_int(&stack) == SUCCESS_TRUE);
}

static void test_queue(void)
{
    Queue_int_8 queue;

    assert(QUEUE_Init_int(&queue) == SUCCESS_TRUE);
    assert(QUEUE_IsEmpty_int(&queue) == SUCCESS_TRUE);
    assert(QUEUE_Enqueue_int(&queue, 1) == SUCCESS_TRUE);
    assert(QUEUE_Enqueue_int(&queue, 2) == SUCCESS_TRUE);
    assert(QUEUE_Peek_int(&queue) == 1);
    assert(QUEUE_Dequeue_int(&queue) == 1);
    assert(QUEUE_Dequeue_int(&queue) == 2);
    assert(QUEUE_IsEmpty_int(&queue) == SUCCESS_TRUE);
}

static void test_tensor(void)
{
    Tensor_int_3 tensor;
    Tensor_int_3 transposed;

    assert(TENSOR_Initialize_int(&tensor, 2, 3, 1) == SUCCESS_TRUE);
    *TENSOR_Locate_int(&tensor, 1, 2, 0) = 42;
    assert(*TENSOR_Locate_int(&tensor, 1, 2, 0) == 42);
    assert(TENSOR_transpose_int(&tensor, &transposed) == SUCCESS_TRUE);
    assert(*TENSOR_Locate_int(&transposed, 2, 1, 0) == 42);
    assert(TENSOR_Free_int(&tensor) == SUCCESS_TRUE);
    assert(TENSOR_Free_int(&transposed) == SUCCESS_TRUE);
}

static void test_list(void)
{
    List_int_int_int *head;
    List_int_int_int *first;
    List_int_int_int *last;

    assert(LIST_Init_int_int_int(&head) == SUCCESS_TRUE);
    first = malloc(sizeof(*first));
    last = malloc(sizeof(*last));
    assert(first != NULL && last != NULL);
    assert(LIST_InsertFront_int_int_int(&head, first) == SUCCESS_TRUE);
    assert(LIST_InsertBack_int_int_int(&head, last) == SUCCESS_TRUE);
    assert(LIST_Size_int_int_int(head) == 2);
    assert(LIST_DeleteFront_int_int_int(&head) == SUCCESS_TRUE);
    assert(LIST_DeleteBack_int_int_int(&head) == SUCCESS_TRUE);
    assert(LIST_Size_int_int_int(head) == 0);
    assert(LIST_Free_int_int_int(&head) == SUCCESS_TRUE);
}

static void test_heap(void)
{
    Heap_int_16 heap;
    int value;

    assert(HEAP_Init_int(&heap) == SUCCESS_TRUE);
    assert(HEAP_Push_int(&heap, 7) == SUCCESS_TRUE);
    assert(HEAP_Push_int(&heap, 2) == SUCCESS_TRUE);
    assert(HEAP_Push_int(&heap, 5) == SUCCESS_TRUE);
    assert(HEAP_Peek_int(&heap, &value) == SUCCESS_TRUE);
    assert(value == 2);
    assert(HEAP_Pop_int(&heap, &value) == SUCCESS_TRUE);
    assert(value == 2);
    assert(HEAP_Pop_int(&heap, &value) == SUCCESS_TRUE);
    assert(value == 5);
    assert(HEAP_Pop_int(&heap, &value) == SUCCESS_TRUE);
    assert(value == 7);
    assert(HEAP_IsEmpty_int(&heap) == SUCCESS_TRUE);
}

static void test_tree(void)
{
    TreeNode_int *root;

    assert(TREE_Init_int(&root) == SUCCESS_TRUE);
    assert(TREE_Insert_int(&root, 5) == SUCCESS_TRUE);
    assert(TREE_Insert_int(&root, 3) == SUCCESS_TRUE);
    assert(TREE_Insert_int(&root, 7) == SUCCESS_TRUE);
    assert(TREE_Insert_int(&root, 6) == SUCCESS_TRUE);
    assert(TREE_Search_int(&root, 6)->data == 6);
    assert(TREE_DeleteNode_int(&root, 5) == SUCCESS_TRUE);
    assert(root->data == 6);
    assert(TREE_LeftRotate_int(&root) == SUCCESS_TRUE);
    assert(root->data == 7);
    assert(TREE_RightRotate_int(&root) == SUCCESS_TRUE);
    TREE_Free_int(root);
}

static void test_algorithms(void)
{
    int data[] = {7, 2, 9, 1, 5, 3};
    const int expected[] = {1, 2, 3, 5, 7, 9};
    size_t index;

    SORT_Quick_int(data, sizeof(data) / sizeof(data[0]));
    for (index = 0; index < sizeof(data) / sizeof(data[0]); index++)
        assert(data[index] == expected[index]);
    assert(SEARCH_Binary_int(data, 6, 5) == 3);
    assert(SEARCH_Binary_int(data, 6, 8) == -1);
}

static void test_graph(void)
{
    Graph graph;
    size_t order[4];
    size_t order_size;

    assert(GRAPH_Init(&graph, 4) == SUCCESS_TRUE);
    assert(GRAPH_AddEdge(&graph, 0, 1, 0) == SUCCESS_TRUE);
    assert(GRAPH_AddEdge(&graph, 1, 2, 0) == SUCCESS_TRUE);
    assert(GRAPH_AddEdge(&graph, 0, 3, 0) == SUCCESS_TRUE);
    assert(GRAPH_HasEdge(&graph, 1, 0) == SUCCESS_TRUE);
    assert(GRAPH_BFS(&graph, 0, order, 4, &order_size) == SUCCESS_TRUE);
    assert(order_size == 4);
    assert(order[0] == 0 && order[1] == 1 && order[2] == 3 && order[3] == 2);
}

static void test_avl(void)
{
    AVLNode *root = NULL;

    assert(AVL_Insert(&root, 30) == SUCCESS_TRUE);
    assert(AVL_Insert(&root, 20) == SUCCESS_TRUE);
    assert(AVL_Insert(&root, 10) == SUCCESS_TRUE);
    assert(root->data == 20);
    assert(AVL_Insert(&root, 40) == SUCCESS_TRUE);
    assert(AVL_Insert(&root, 50) == SUCCESS_TRUE);
    assert(AVL_Height(root) <= 3);
    assert(AVL_Search(root, 40) != NULL);
    assert(AVL_Delete(&root, 20) == SUCCESS_TRUE);
    assert(AVL_Search(root, 20) == NULL);
    assert(AVL_Free(root) == SUCCESS_TRUE);
}

int main(void)
{
    test_stack();
    test_queue();
    test_tensor();
    test_list();
    test_heap();
    test_tree();
    test_algorithms();
    test_graph();
    test_avl();
    return 0;
}
